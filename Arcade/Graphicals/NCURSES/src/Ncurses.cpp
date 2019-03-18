/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Ncurses.cpp
*/

#include "Ncurses.hpp"

uint8_t Ncurses::getGameKeyState() const noexcept
{
    return NEXT_GAME_LIB;
}

uint8_t Ncurses::getCoreKeyState() const noexcept
{
    return UP;
}

void Ncurses::sendGameKeyInput(GameKey) noexcept
{}

void Ncurses::sendCoreKeyInput(CoreKey) noexcept
{}

IRenderer &Ncurses::getRenderer() noexcept
{
    return _render;
}

bool Ncurses::isCloseRequested() const noexcept
{
    return false;
}