/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SDL tests
*/

#include <criterion/criterion.h>

#include "SDL.hpp"

Test(SDL, getKeysStates)
{
    SDL sdl;

    sdl.pollEvents();
    cr_assert_eq(sdl.getGameKeyState(), 0);
    cr_assert_eq(sdl.getCoreKeyState(), 0);
}

Test(SDL, sendKeysStates)
{
    SDL sdl;

    sdl.sendGameKeyInput(Arcade::IGraphicLib::UP);
    sdl.sendCoreKeyInput(Arcade::IGraphicLib::EXIT);
    sdl.pollEvents();
    cr_assert_eq(sdl.getGameKeyState(), 0);
    cr_assert_eq(sdl.getCoreKeyState(), 0);
}

Test(SDL, closeRequested)
{
    SDL sdl;

    sdl.pollEvents();
    cr_assert_eq(sdl.isCloseRequested(), false);
}