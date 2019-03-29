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
        cell.pos = {x, y};
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
        _playerSprite->setPosAndSize({_playerPos.x, _playerPos.y, PLAYER_WIDTH, PLAYER_HEIGHT});

    for (auto &cell : _cells)
        if (cell.hasObstacle)
            _updateObstacle(cell);
}

void Centipede::render(Arcade::IGraphicLib *graphic)
{
    auto &renderer = graphic->getRenderer();

    renderer.clear();
    for (const auto &cell : _cells)
        if (cell.hasObstacle && cell.sprite != nullptr)
            renderer.drawSprite(cell.sprite);
    renderer.drawSprite(_playerSprite);
    renderer.display();
}

bool Centipede::isCloseRequested() const noexcept
{
    return _closeRequested;
}

void Centipede::reloadResources(Arcade::IGraphicLib *graphic)
{
    _freeResources();

    _spriteSheet = graphic->createTexture(SPRITE_SHEET, sizeof(SPRITE_SHEET), Arcade::Color(0, 255, 127));
    _playerSprite = graphic->createSprite(_spriteSheet, PLAYER_SPRITE_RECT,
                                          {_playerPos.x, _playerPos.y, PLAYER_WIDTH, PLAYER_HEIGHT});

    for (auto &cell : _cells)
        if (cell.hasObstacle)
            cell.sprite = graphic->createSprite(_spriteSheet, OBSTACLE_SPRITE_RECTS[cell.obstacleHealth - 1],
                                                {cell.pos.x / CELL_COUNT_X * BOARD_WIDTH,
                                                 cell.pos.y / CELL_COUNT_Y * BOARD_HEIGHT, CELL_SIZE, CELL_SIZE});
}

void Centipede::_updateObstacle(Centipede::Cell &cell)
{
    if (cell.sprite)
        cell.sprite->setTextureRect(OBSTACLE_SPRITE_RECTS[cell.obstacleHealth - 1]);
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
