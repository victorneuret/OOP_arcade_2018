/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Centipede.cpp
*/

#include <random>

#include "Centipede.hpp"
#include "CentipedeTexture.hpp"

Centipede::Centipede()
{
    double x = 0;
    double y = 0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (auto &cell : _cells) {
        cell.rect.pos = {x / CELL_COUNT_X * BOARD_WIDTH, y / CELL_COUNT_Y * BOARD_HEIGHT};
        cell.hasObstacle = dis(gen) <= OBSTACLE_PERCENTAGE / 100.0;

        if (++x >= CELL_COUNT_X) {
            x = 0;
            if (++y >= CELL_COUNT_Y)
                break;
        }
    }
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

    for (auto &cell : _cells)
        if (cell.hasObstacle)
            _updateObstacle(cell);

    if (_isShooting) {
        _shotPos -= {0, SHOT_SPEED * _deltaTime};
        if (_shotPos.y < -SHOT_HEIGHT)
            _isShooting = false;
        else
            _checkShotCollision();
    }
}

void Centipede::render(Arcade::IGraphicLib *graphic)
{
    auto &renderer = graphic->getRenderer();

    renderer.clear();

    for (const auto &cell : _cells)
        if (cell.hasObstacle && cell.sprite != nullptr)
            renderer.drawSprite(cell.sprite);
    renderer.drawSprite(_playerSprite);
    if (_isShooting)
        renderer.drawRectangle({_shotPos, {SHOT_WIDTH, SHOT_HEIGHT}}, Arcade::Color(0xa7, 0x42, 0x42));

    renderer.display();
}

void Centipede::reloadResources(Arcade::IGraphicLib *graphic)
{
    _freeResources();

    _spriteSheet = graphic->createTexture( SPRITE_SHEET, sizeof(SPRITE_SHEET));
    _playerSprite = graphic->createSprite(_spriteSheet, PLAYER_SPRITE_RECT,
                                          {_playerPos, {PLAYER_WIDTH, PLAYER_HEIGHT}});

    _playerSprite->setFallbackColor(Arcade::Color(0xff, 0xff, 0xb7));
    for (auto &cell : _cells)
        if (cell.hasObstacle) {
            cell.sprite = graphic->createSprite(_spriteSheet, OBSTACLE_SPRITE_RECTS[cell.obstacleHealth - 1], cell.rect);
            cell.sprite->setFallbackColor(Arcade::Color(0xf4, 0xa7, 0xb7));
        }
}

void Centipede::_updateObstacle(Centipede::Cell &cell)
{
    if (cell.sprite) {
        if (cell.obstacleHealth > 0)
            cell.sprite->setTextureRect(OBSTACLE_SPRITE_RECTS[cell.obstacleHealth - 1]);
        else
            cell.sprite->setTextureRect(DESTROYED_OBSTACLE);
    }
}

bool Centipede::_rectanglesCollide(const Arcade::Rect &rectA, const Arcade::Rect &rectB)
{
    return (rectA.pos.x < rectB.pos.x + rectB.size.x && rectA.pos.x + rectA.size.x > rectB.pos.x &&
            rectA.pos.y < rectB.pos.y + rectB.size.y && rectA.pos.y + rectA.size.y > rectB.pos.y);
}

void Centipede::_checkShotCollision()
{
    const Arcade::Rect shotRect = {_shotPos, {SHOT_WIDTH, SHOT_HEIGHT}};

    for (auto &cell : _cells) {
        if (!cell.hasObstacle)
            continue;

        if (cell.obstacleHealth > 0 && _rectanglesCollide(shotRect, cell.rect)) {
            cell.obstacleHealth -= 1;
            _isShooting = false;
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
