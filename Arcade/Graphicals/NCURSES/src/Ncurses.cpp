/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Ncurses.cpp
*/

#include "Ncurses.hpp"
#include "NcursesSprite.hpp"
#include "NcursesTexture.hpp"

Ncurses::Ncurses()
    : _render()
{}

uint8_t Ncurses::getGameKeyState() const noexcept
{
    return _gameKey;
}

uint8_t Ncurses::getCoreKeyState() const noexcept
{
    return _coreKey;
}

void Ncurses::sendGameKeyInput(GameKey key) noexcept
{
    _gameKey = key;
}

void Ncurses::sendCoreKeyInput(CoreKey key) noexcept
{
    _coreKey = key;
}

void Ncurses::pollEvents()
{
    int key = getch();

    _gameKey = 0;
    _coreKey = 0;
    if (_gameKeys.find(key) != _gameKeys.end())
        _gameKey = _gameKeys.at(key);
    if (_coreKeys.find(key) != _coreKeys.end())
        _coreKey = _coreKeys.at(key);
}

Arcade::ATexture *Ncurses::createTexture(const void *buffer, const size_t &len)
{
    return new NcursesTexture(buffer, len);
}

Arcade::ASprite *Ncurses::createSprite(const Arcade::ATexture *texture, const Arcade::Rect &spriteSheetRect, const Arcade::Rect &posAndSize)
{
    return new NcursesSprite(texture, spriteSheetRect, posAndSize);
}

Arcade::IRenderer &Ncurses::getRenderer() noexcept
{
    return _render;
}

bool Ncurses::isCloseRequested() const noexcept
{
    return false;
}
