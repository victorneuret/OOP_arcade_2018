/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** MainMenu.cpp
*/

#include "MainMenu.hpp"

void MainMenu::tick()
{}

void MainMenu::render(Arcade::IGraphicLib *graphic)
{
    if (!graphic)
        return;

    uint8_t key = graphic->getGameKeyState();

    graphic->getRenderer().clear();
    if (key == Arcade::IGraphicLib::UP)
        graphic->getRenderer().drawText("UP", 20, {10, 10}, {255, 0, 0});
    else if (key == Arcade::IGraphicLib::DOWN)
        graphic->getRenderer().drawText("DOWN", 20, {10, 10}, {255, 0, 0});
    else if (key == Arcade::IGraphicLib::LEFT)
        graphic->getRenderer().drawText("LEFT", 20, {10, 10}, {255, 0, 0});
    else if (key == Arcade::IGraphicLib::RIGHT)
        graphic->getRenderer().drawText("RIGHT", 20, {10, 10}, {255, 0, 0});

    graphic->getRenderer().display();
}

bool MainMenu::isCloseRequested() const noexcept
{
    return false;
}