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

Arcade::IRenderer &Ncurses::getRenderer() noexcept
{
    return _render;
}

bool Ncurses::isCloseRequested() const noexcept
{
    return false;
}

void Ncurses::pollEvents()
{}
