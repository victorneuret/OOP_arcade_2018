/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** MainMenu.cpp
*/

#include <sstream>

#include "MainMenu.hpp"

int MainMenu::INDEX = 0;

void MainMenu::tick(Arcade::IGraphicLib *graphic)
{
    if (!graphic)
        return;

    uint8_t key = graphic->getGameKeyState();

    for (const auto &c : _gameKeys) {
        if (c.first & key)
            (this->*c.second)();
    }
}

void MainMenu::moveUp()
{
    if (_selection.second > 0)
        _selection.second -= 1;
}

void MainMenu::moveDown()
{
    _selection.second += 1;
}

void MainMenu::moveLeft()
{
    if (_selection.first > 0)
        _selection.first -= 1;
}

void MainMenu::moveRight()
{
    _selection.first += 1;
}

void MainMenu::primaryPressed()
{}

void MainMenu::render(Arcade::IGraphicLib *graphic)
{
    std::stringstream str;

    if (!graphic)
        return;
    str << " hello " << INDEX;
    graphic->getRenderer().clear();
    graphic->getRenderer().drawText(str.str(), 10, {0.5, 0.5}, {255, 0, 0});
    graphic->getRenderer().drawRectangle({{0, 0}, {0.5, 0.5}}, {0, 0, 255});
    graphic->getRenderer().display();
}

bool MainMenu::isCloseRequested() const noexcept
{
    return false;
}