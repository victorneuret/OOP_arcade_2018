/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** MainMenu.cpp
*/

#include <sstream>
#include <MainMenu.hpp>

#include "MainMenu.hpp"

void MainMenu::init(Arcade::IGraphicLib *)
{
}

void MainMenu::tick(Arcade::IGraphicLib *graphic, double deltaTime)
{
    _deltaTime = deltaTime;

    if (!graphic)
        return;

    uint8_t key = graphic->getGameKeyState();

    for (const auto &c : _gameKeys)
        if (c.first & key)
            c.second();
}

void MainMenu::tick(Arcade::IGraphicLib *graphic, double deltaTime, const Arcade::IMenu::CoreExtension &core)
{
    tick(graphic, deltaTime);
    if (_selection.first > 0 && _selection.first >= core.games.size())
        _selection.first -= 1;
    else if (_selection.second > 0 && _selection.second >= core.libs.size())
        _selection.second -= 1;
}

void MainMenu::moveUp()
{
    if (_selection.second > 0)
        _selection.second -= 0.5 * _deltaTime;
}

void MainMenu::moveDown()
{
    if (_selection.second < 1)
        _selection.second += 0.5 * _deltaTime;
}

void MainMenu::moveLeft()
{
    if (_selection.first > 0)
        _selection.first -= 0.5 * _deltaTime;
}

void MainMenu::moveRight()
{
    if (_selection.first < 1)
        _selection.first += 0.5 * _deltaTime;
}

void MainMenu::primaryPressed()
{}

void MainMenu::render(Arcade::IGraphicLib *)
{}

void MainMenu::render(Arcade::IGraphicLib *graphic, const Arcade::IMenu::CoreExtension &core)
{
    if (!graphic)
        return;
    graphic->getRenderer().clear();
    graphic->getRenderer().drawText("this is a test", 16, Arcade::Vector(_selection.first, _selection.second),
                                    Arcade::Color(0, 255, 0));
    graphic->getRenderer().drawRectangle(Arcade::Rect(0.33, 0.33, 0.66, 0.66), Arcade::Color(0, 42, 200), false);
    graphic->getRenderer().drawRectangle(Arcade::Rect(0.45, 0.45, 0.1, 0.1), Arcade::Color(0, 200, 42), true);
    //graphic->getRenderer().drawRectangle(Arcade::Rect{0, 0, 1, 1}, Arcade::Color{255, 255, 255, 255}, true);
    for (size_t i = 0; i < core.libs.size(); i++) {
        graphic->getRenderer().drawText(core.libs[i].substr(core.libs[i].find("/lib_arcade_") + 12, core.libs[i].size() - 4), 10,
            Arcade::Vector(0, static_cast<double>(i) / 15), Arcade::Color{255, 255, 255});
    }
    for (size_t i = 0; i < core.games.size(); i++) {
        graphic->getRenderer().drawText(core.games[i].substr(core.games[i].find("/lib_arcade_") + 12, core.games[i].size() - 4), 10,
            Arcade::Vector(0, 0.5 + static_cast<double>(i) / 15), Arcade::Color{255, 255, 255});
    }
    graphic->getRenderer().display();
}

bool MainMenu::isCloseRequested() const noexcept
{
    return false;
}

void MainMenu::reloadResources(Arcade::IGraphicLib *)
{}
