/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** MainMenu.cpp
*/

#include <sstream>

#include "MainMenu.hpp"


void MainMenu::tick(Arcade::IGraphicLib *graphic)
{
    if (!graphic)
        return;

    uint8_t key = graphic->getGameKeyState();

    for (const auto &c : _gameKeys) {
        if (c.first & key)
            c.second();
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
    if (!graphic)
        return;
    graphic->getRenderer().clear();
    graphic->getRenderer().drawRectangle(Arcade::Rect{0.0, 0.0, 0.5, 0.5}, Arcade::Color{255, 0, 0});
    graphic->getRenderer().drawRectangle(Arcade::Rect{0.5, 0.5, 0.5, 0.5}, Arcade::Color{0, 0, 255});
    graphic->getRenderer().drawText("this is a test", 10, Arcade::Vector{
        0.5 + static_cast<double>(_selection.first) / 40,
        0.5 + static_cast<double>(_selection.second) / 40}, Arcade::Color{255, 0, 0});
    graphic->getRenderer().display();
}

bool MainMenu::isCloseRequested() const noexcept
{
    return false;
}

void MainMenu::reloadResources(Arcade::IGraphicLib *)
{}
