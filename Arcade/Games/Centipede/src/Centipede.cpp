/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Centipede.cpp
*/

#include <chrono>
#include <iostream>

#include "Random.hpp"
#include "Centipede.hpp"
#include "CentipedeTexture.hpp"

Centipede::Centipede()
{
    double x = 0;
    double y = 0;

    for (auto &cell : _cells) {
        cell.absolutePos = {x, y};
        cell.rect.pos = {x / CELL_COUNT_X * BOARD_WIDTH, y / CELL_COUNT_Y * BOARD_HEIGHT};

        if (cell.rect.pos.y >= OBS_SPAWN_OFFSET && cell.rect.pos.y + CELL_SIZE < OBS_SPAWN_OFFSET + OBS_SPAWN_HEIGHT)
            cell.type = Random::range() <= OBS_PRCT / 100.0 ? Cell::OBSTACLE : Cell::EMPTY;

        if (++x >= CELL_COUNT_X) {
            x = 0;
            if (++y >= CELL_COUNT_Y)
                break;
        }
    }

    _createSnake();
}

Centipede::~Centipede()
{
    _freeResources();
}

void Centipede::init(Arcade::IGraphicLib *graphic)
{
    reloadResources(graphic);
}

void Centipede::tick(Arcade::IGraphicLib *graphic, double deltaTime)
{
    _deltaTime = deltaTime;

    const auto key = graphic->getGameKeyState();
    for (const auto &gameKey : _gameKeys)
        if (gameKey.first & key)
            gameKey.second();

    if (_playerAlive) {
        if (_playerSprite)
            _playerSprite->setPosAndSize({_playerPos, {PLAYER_WIDTH, PLAYER_HEIGHT}});

        _updateSnakes();

        for (auto &cell : _cells)
            if (cell.type == Cell::OBSTACLE)
                _updateObstacle(cell);

        if (_isShooting) {
            _shotPos -= {0, SHOT_SPEED * _deltaTime};
            if (_shotPos.y < -SHOT_HEIGHT)
                _isShooting = false;
            else
                _checkShotCollisions();
        }
        _checkPlayerCollisions();

        _score += _scorePerSecond * _deltaTime;
    }
}

void Centipede::render(Arcade::IGraphicLib *graphic)
{
    auto &renderer = graphic->getRenderer();

    renderer.clear();

    if (_playerAlive) {
        for (const auto &cell : _cells) {
            if (cell.type == Cell::OBSTACLE && cell.sprite != nullptr) {
                cell.sprite->setFallbackColor({255, 255, 255, static_cast<uint8_t>(cell.health / 5.0 * 255)});
                renderer.drawSprite(cell.sprite);
            } else if (cell.type == Cell::SNAKE_HEAD) {
                renderer.drawRectangle(cell.rect, {255, 0, 0});
            } else if (cell.type == Cell::SNAKE_BODY) {
                renderer.drawRectangle(cell.rect, {127, 0, 0});
            }
        }
        renderer.drawSprite(_playerSprite);
        if (_isShooting)
            renderer.drawRectangle({_shotPos, {SHOT_WIDTH, SHOT_HEIGHT}}, Arcade::Color(255, 0, 0));
        renderer.drawText("Score: " + std::to_string(static_cast<long>(_score)), 18, {0.01, 0.01}, {255, 255, 255});
    } else {
        renderer.drawText("GAME OVER - Score: " + std::to_string(static_cast<long>(_score)), 22, {0.25, 0.25},
                          {255, 255, 255});
    }

    renderer.display();
}

void Centipede::reloadResources(Arcade::IGraphicLib *graphic)
{
    _freeResources();

    _spriteSheet = graphic->createTexture(SPRITE_SHEET, sizeof(SPRITE_SHEET));
    _playerSprite = graphic->createSprite(_spriteSheet, PLAYER_SPRITE_RECT,
                                          {_playerPos, {PLAYER_WIDTH, PLAYER_HEIGHT}});
    _playerSprite->setFallbackColor({0, 255, 127});

    for (auto &cell : _cells) {
        if (cell.type == Cell::OBSTACLE) {
            cell.sprite = graphic->createSprite(_spriteSheet, OBSTACLE_SPRITE_RECTS[cell.health - 1],
                                                cell.rect);
            cell.sprite->setFallbackColor({127, 127, 0});
        }
    }
}

void Centipede::_updateObstacle(Centipede::Cell &cell)
{
    if (cell.sprite) {
        if (cell.health > 0)
            cell.sprite->setTextureRect(OBSTACLE_SPRITE_RECTS[cell.health - 1]);
        else
            cell.sprite->setTextureRect(DESTROYED_OBSTACLE);
    }
}

bool Centipede::_rectanglesCollide(const Arcade::Rect &rectA, const Arcade::Rect &rectB)
{
    return (rectA.pos.x < rectB.pos.x + rectB.size.x && rectA.pos.x + rectA.size.x > rectB.pos.x &&
            rectA.pos.y < rectB.pos.y + rectB.size.y && rectA.pos.y + rectA.size.y > rectB.pos.y);
}

Centipede::Cell &Centipede::_getCell(size_t x, size_t y)
{
    for (auto &cell : _cells)
        if (cell.absolutePos.x == x && cell.absolutePos.y == y)
            return cell;
    throw std::runtime_error("Cell (" + std::to_string(x) + ", " + std::to_string(y) + ") not found");
}

Centipede::Cell &Centipede::_getCell(const Arcade::Vector &vec)
{
    return _getCell(static_cast<size_t>(vec.x), static_cast<size_t>(vec.y));
}

Centipede::Snake &Centipede::_getSnake(size_t x, size_t y)
{
    return _getSnake({static_cast<double>(x), static_cast<double>(y)});
}

Centipede::Snake &Centipede::_getSnake(const Arcade::Vector &vec)
{
    for (auto &snake : _snakes)
        for (auto &part : snake.body)
            if (static_cast<size_t>(part.x) == static_cast<size_t>(vec.x) &&
                static_cast<size_t>(part.y) == static_cast<size_t>(vec.y))
                return snake;
    throw std::runtime_error("Snake " + std::to_string(vec.x) + ", " + std::to_string(vec.y) + " not found");
}

size_t Centipede::_getSnakeIndex(const Snake &snake)
{
    for (size_t i = 0; i < _snakes.size(); ++i)
        if (_snakes[i] == snake)
            return i;
    throw std::runtime_error("Snake index not found");
}

void Centipede::_createSnake(bool forceUpdate)
{
    const auto snakeSize = Random::getUnsigned(SNAKE_SIZE_MIN_MAX.first, SNAKE_SIZE_MIN_MAX.second);
    Snake snake{};

    snake.goingRight = Random::getBool();
    for (size_t i = 0; i < snakeSize; ++i)
        snake.body.emplace_back(CELL_COUNT_X / 2.0 + (snake.goingRight ? -i : i), 0);

    _snakes.push_back(snake);

    if (forceUpdate)
        _updateSnakes(true);
}

void Centipede::_updateSnakes(bool force)
{
    static auto lastSpawn = std::chrono::system_clock::now();
    static auto lastUpdate = std::chrono::system_clock::now();
    auto now = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed = now - lastUpdate;
    if (force || elapsed.count() >= SNAKE_MOVE_INTERVAL) {
        for (size_t i = 0; i < _snakes.size(); ++i) {
            auto &snake = _snakes[i];
            Arcade::Vector newPos = snake.body.front();

            newPos += {snake.goingRight ? 1.0 : -1.0, 0};
            if (newPos.x < 0 || newPos.x > CELL_COUNT_X || _getCell(newPos).type == Cell::OBSTACLE) {
                newPos += {snake.goingRight ? -1.0 : 1.0, 1};
                snake.goingRight = !snake.goingRight;
            }
            if (newPos.y >= CELL_COUNT_Y - 1) {
                _score -= _scorePerKill * 2;
                for (auto &cell : snake.body)
                    _getCell(cell).type = Cell::EMPTY;
                _snakes.erase(_snakes.begin() + i);
                _createSnake(false);
                continue;
            }

            _getCell(snake.body.back()).type = Cell::EMPTY;
            snake.body.erase(snake.body.end());
            snake.body.insert(snake.body.begin(), newPos);

            for (auto &part : snake.body)
                _getCell(part).type = Cell::SNAKE_BODY;
            _getCell(snake.body.front()).type = Cell::SNAKE_HEAD;
        }

        lastUpdate = now;
    }

    elapsed = now - lastSpawn;
    if (elapsed.count() >= SNAKE_SPAWN_INTERVAL || _snakes.empty()) {
        _createSnake(false);
        lastSpawn = now;
    }
}

void Centipede::_checkShotCollisions()
{
    const Arcade::Rect shotRect = {_shotPos, {SHOT_WIDTH, SHOT_HEIGHT}};

    for (auto &cell : _cells) {
        if (cell.type == Cell::EMPTY)
            continue;

        const auto collision = _rectanglesCollide(shotRect, cell.rect);

        if (cell.type == Cell::OBSTACLE) {
            if (cell.health > 0 && collision) {
                cell.health -= 1;
                _isShooting = false;
                if (cell.health == 0) {
                    _score += _scorePerObstacleDestroyed;
                    cell.type = Cell::EMPTY;
                }
                return;
            }
        } else if (cell.type == Cell::SNAKE_HEAD) {
            if (collision) {
                auto &snake = _getSnake(cell.absolutePos);
                _score += _scorePerKill;
                for (auto &part : snake.body)
                    _getCell(part).type = Cell::EMPTY;
                _snakes.erase(_snakes.begin() + _getSnakeIndex(snake));
            }
        }
    }
}

void Centipede::_checkPlayerCollisions()
{
    for (auto &snake : _snakes) {
        for (auto &part : snake.body) {
            if (_rectanglesCollide({_playerPos, {PLAYER_WIDTH, PLAYER_HEIGHT}}, _getCell(part).rect)) {
                _playerAlive = false;
                return;
            }
        }
    }
}

void Centipede::_shoot()
{
    if (_isShooting)
        return;

    _isShooting = true;
    _shotPos = {_playerPos.x + PLAYER_WIDTH / 2.0, _playerPos.y};
}

void Centipede::_moveUp()
{
    if (_playerPos.y > 0.8)
        _playerPos.y -= PLAYER_SPEED * _deltaTime;
}

void Centipede::_moveDown()
{
    if (_playerPos.y < 1 - PLAYER_HEIGHT)
        _playerPos.y += PLAYER_SPEED * _deltaTime;
}

void Centipede::_moveLeft()
{
    if (_playerPos.x > 0)
        _playerPos.x -= PLAYER_SPEED * _deltaTime;
}

void Centipede::_moveRight()
{
    if (_playerPos.x < 1 - PLAYER_WIDTH)
        _playerPos.x += PLAYER_SPEED * _deltaTime;
}

void Centipede::_freeResources()
{
    delete _spriteSheet;
    delete _playerSprite;

    for (auto &cell : _cells)
        delete cell.sprite;
}

bool Centipede::isCloseRequested() const noexcept
{
    return _closeRequested;
}

bool Centipede::Snake::operator==(const Centipede::Snake &rhs) const
{
    return body == rhs.body &&
           goingRight == rhs.goingRight;
}

bool Centipede::Snake::operator!=(const Centipede::Snake &rhs) const
{
    return !(rhs == *this);
}
