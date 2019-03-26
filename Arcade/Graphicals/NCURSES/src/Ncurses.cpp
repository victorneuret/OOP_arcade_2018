/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Ncurses.cpp
*/

#include "Ncurses.hpp"

Ncurses::Ncurses()
    : _render()
{}

uint8_t Ncurses::getGameKeyState() const noexcept
{
    int key = getch();

    if (_gameKeys.find(key) != _gameKeys.end())
        return _gameKeys.at(key);
    return 0;
}

uint8_t Ncurses::getCoreKeyState() const noexcept
{
    int key = getch();

    if (_coreKeys.find(key) != _coreKeys.end())
        return _coreKeys.at(key);
    return 0;
}

void Ncurses::sendGameKeyInput(GameKey) noexcept
{}

void Ncurses::sendCoreKeyInput(CoreKey) noexcept
{}

void Ncurses::pollEvents()
{}

Arcade::ATexture *Ncurses::createTexture(const void *, const size_t &, const Arcade::Color &)
{
    throw std::runtime_error("Ncurses::createTexture: Not implemented");
}

Arcade::ASprite *Ncurses::createSprite(const Arcade::ATexture *, const Arcade::Rect &, const Arcade::Rect &)
{
    throw std::runtime_error("Ncurses::createSprite: Not implemented");
}

Arcade::ATexture *Ncurses::recreateTexture(const Arcade::ATexture &)
{
    throw std::runtime_error("Ncurses::recreateTexture: Not implemented");
}

Arcade::ASprite *Ncurses::recreateSprite(const Arcade::ASprite &)
{
    throw std::runtime_error("Ncurses::recreateSprite: Not implemented");
}

Arcade::IRenderer &Ncurses::getRenderer() noexcept
{
    return _render;
}

bool Ncurses::isCloseRequested() const noexcept
{
    return false;
}
