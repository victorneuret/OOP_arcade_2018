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
        cell.rect.pos = {x / CELL_COUNT_X * BOARD_WIDTH, y / CELL_COUNT_Y * BOARD_HEIGHT + BOARD_OFFSET};
        cell.type = Random::range() <= OBSTACLE_PERCENTAGE / 100.0 ? Cell::OBSTACLE : Cell::EMPTY;

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
            _checkShotCollision();
    }

    _score += _scorePerSecond * _deltaTime;
}

void Centipede::render(Arcade::IGraphicLib *graphic)
{
    auto &renderer = graphic->getRenderer();

    renderer.clear();

    for (const auto &cell : _cells) {
        if (cell.type == Cell::OBSTACLE && cell.sprite != nullptr)
            renderer.drawSprite(cell.sprite);
        else if (cell.type == Cell::SNAKE_HEAD)
            renderer.drawRectangle(cell.rect, {255, 0, 127});
        else if (cell.type == Cell::SNAKE_BODY)
            renderer.drawRectangle(cell.rect, {255, 127, 127});
    }
    renderer.drawSprite(_playerSprite);
    if (_isShooting)
        renderer.drawRectangle({_shotPos, {SHOT_WIDTH, SHOT_HEIGHT}}, Arcade::Color(0xa7, 0x42, 0x42));

    renderer.drawText("Score: " + std::to_string(static_cast<long>(_score)), 18, {0.01, 0.01}, {255, 255, 255});

    renderer.display();
}

void Centipede::reloadResources(Arcade::IGraphicLib *graphic)
{
    _freeResources();

    _spriteSheet = graphic->createTexture(SPRITE_SHEET, sizeof(SPRITE_SHEET));
    _playerSprite = graphic->createSprite(_spriteSheet, PLAYER_SPRITE_RECT,
                                          {_playerPos, {PLAYER_WIDTH, PLAYER_HEIGHT}});

    _playerSprite->setFallbackColor(Arcade::Color(0xff, 0xff, 0xb7));
    for (auto &cell : _cells)
        if (cell.type == Cell::OBSTACLE)
            cell.sprite = graphic->createSprite(_spriteSheet, OBSTACLE_SPRITE_RECTS[cell.health - 1],
                                                cell.rect);
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

void Centipede::_createSnake()
{
    const auto snakeSize = Random::getUnsigned(SNAKE_SIZE_MIN_MAX.first, SNAKE_SIZE_MIN_MAX.second);
    Snake snake{};

    snake.goingRight = Random::getBool();
    for (size_t i = 0; i < snakeSize; ++i)
        snake.body.emplace_back(CELL_COUNT_X / 2.0 + (snake.goingRight ? -i : i), 0);

    _snakes.push_back(snake);
    _updateSnakes(true);
}

void Centipede::_updateSnakes(bool force)
{
    static auto lastUpdate = std::chrono::system_clock::now();
    auto now = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed = now - lastUpdate;
    if (!force && elapsed.count() < SNAKE_MOVE_INTERVAL)
        return;

    for (auto &snake : _snakes) {
        Arcade::Vector newPos = snake.body.front();

        newPos += {snake.goingRight ? 1.0 : -1.0, 0};

        if (newPos.x < 0 || newPos.x > CELL_COUNT_X) {
            newPos += {snake.goingRight ? -1.0 : 1.0, 1};
            snake.goingRight = !snake.goingRight;
        }

        _getCell(snake.body.back()).type = Cell::EMPTY;
        snake.body.erase(snake.body.end());
        snake.body.insert(snake.body.begin(), newPos);
        for (size_t i = 0; i < _snakes.size(); ++i)
            _getCell(snake.body[i]).type = i == 0 ? Cell::SNAKE_HEAD : Cell::SNAKE_BODY;
    }

    lastUpdate = now;
}

void Centipede::_checkShotCollision()
{
    const Arcade::Rect shotRect = {_shotPos, {SHOT_WIDTH, SHOT_HEIGHT}};

    for (auto &cell : _cells) {
        if (cell.type != Cell::OBSTACLE)
            continue;

        if (cell.health > 0 && _rectanglesCollide(shotRect, cell.rect)) {
            cell.health -= 1;
            _isShooting = false;
            if (cell.health == 0)
                _score += _scorePerObstacleDestroyed;
            return;
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
