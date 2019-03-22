/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** MainMenu.cpp
*/

#include "MainMenu.hpp"
#include <iostream>

void MainMenu::tick()
{}

void MainMenu::render(Arcade::IGraphicLib *graphic)
{
    if (!graphic)
        return;

    uint8_t key = graphic->getGameKeyState();

    graphic->getRenderer().clear();
    if (key == Arcade::IGraphicLib::UP) {
        graphic->getRenderer().drawRectangle(Arcade::Rect(0, 0, 0.5, 0.5), Arcade::Color(0xff, 0x00, 0x00));
        std::cout << "UP" << std::endl;
    }
    else if (key == Arcade::IGraphicLib::DOWN)
        graphic->getRenderer().drawRectangle(Arcade::Rect(0.5, 0, 0.5, 0.5), Arcade::Color(0xff, 0xff, 0xff));
    else if (key == Arcade::IGraphicLib::LEFT)
        graphic->getRenderer().drawRectangle(Arcade::Rect(0, 0.5, 0.5, 0.5), Arcade::Color(0x00, 0xff, 0x00), false);
    else if (key == Arcade::IGraphicLib::RIGHT)
        graphic->getRenderer().drawRectangle(Arcade::Rect(0.5, 0.5, 0.5, 0.5), Arcade::Color(0x00, 0x00, 0xff), false);
    graphic->getRenderer().display();
}

bool MainMenu::isCloseRequested() const noexcept
{
    return false;
}