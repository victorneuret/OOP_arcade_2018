/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** SDL tests
*/

#include <criterion/criterion.h>
#include <cstdio>

#include "SDLRenderer.hpp"

Test(SDLRenderer, constructor)
{
    SDLRenderer renderer;
    renderer.~SDLRenderer();
}

Test(SDLRenderer, renderRect)
{
    SDLRenderer renderer;

    renderer.drawRectangle(Arcade::Rect({10, 10}, {20, 20}), Arcade::Color(42, 42, 42), true);
    renderer.drawRectangle(Arcade::Rect({20, 20}, {30, 30}), Arcade::Color(42, 42, 42), false);
}

Test(SDLRenderer, renderText)
{
    SDLRenderer renderer;

    renderer.drawText("test", 8, {42, 42}, Arcade::Color(0xff, 0xff, 0xff));
}

Test(SDLRenderer, fontNotFound)
{
    std::rename("res/arcade.ttf", "res/arcade");
    SDLRenderer renderer;

    cr_assert_throw(renderer.drawText("test", 8, {42, 42}, Arcade::Color(0xff, 0xff, 0xff)), std::runtime_error);

    std::rename("res/arcade", "res/arcade.ttf");
}

Test(SDLRenderer, displayAndClear)
{
    SDLRenderer renderer;

    renderer.clear();
    renderer.display();
}


