/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Centipede.cpp
*/

#include <Centipede.hpp>

#include "Centipede.hpp"

Centipede::~Centipede()
{
}

void Centipede::init(Arcade::IGraphicLib *graphic)
{
}

void Centipede::tick(Arcade::IGraphicLib *graphic, double deltaTime)
{
    _deltaTime = deltaTime;

    const auto key = graphic->getGameKeyState();

    for (const auto &gameKey : _gameKeys)
        if (gameKey.first & key)
            gameKey.second();
}

void Centipede::render(Arcade::IGraphicLib *graphic)
{
    auto &renderer = graphic->getRenderer();

    renderer.clear();
    renderer.drawRectangle(Arcade::Rect(_playerPos.x, _playerPos.y, PLAYER_WIDTH, PLAYER_HEIGHT),
                           Arcade::Color(255, 255, 255));
    renderer.display();
}

bool Centipede::isCloseRequested() const noexcept
{
    return _closeRequested;
}

void Centipede::reloadResources(Arcade::IGraphicLib *)
{
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
