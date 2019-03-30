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
    if (_gameKeys.find(_key) != _gameKeys.end())
        return _gameKeys.at(_key);
    return 0;
}

uint8_t Ncurses::getCoreKeyState() const noexcept
{
    if (_coreKeys.find(_key) != _coreKeys.end())
        return _coreKeys.at(_key);
    return 0;
}

void Ncurses::sendGameKeyInput(GameKey key) noexcept
{
    _key = key;
}

void Ncurses::sendCoreKeyInput(CoreKey key) noexcept
{
    _key = key;
}

void Ncurses::pollEvents()
{
    _key = getch();
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
