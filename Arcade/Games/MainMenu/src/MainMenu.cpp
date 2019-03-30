/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** MainMenu.cpp
*/

#include <sstream>
#include <MainMenu.hpp>
#include <string.h>

#include "MainMenu.hpp"

void MainMenu::init(Arcade::IGraphicLib *)
{
}

void MainMenu::tick(Arcade::IGraphicLib *, double )
{}

void MainMenu::tick(Arcade::IGraphicLib *graphic, double deltaTime, const Arcade::IMenu::CoreExtension &core)
{
    _deltaTime = deltaTime;

    if (!graphic)
        return;

    uint8_t key = graphic->getGameKeyState();

    for (const auto &c : _gameKeys) {
        if (c.first & key)
            c.second(core);
    }
}

void MainMenu::moveUp(const CoreExtension &)
{
    if (_selection.second >= 1)
        _selection.second -= 1;
}

void MainMenu::moveDown(const CoreExtension &core)
{
    if ((_selection.first == SELECT_GAME && _selection.second < core.games.size() - 1) ||
        (_selection.first == SELECT_LIB && _selection.second < core.libs.size() - 1))
        _selection.second += 1;
}

void MainMenu::moveLeft(const CoreExtension &core)
{
    if (_selection.first == SELECT_LIB)
        _selection.first = SELECT_GAME;
    if (_selection.second > core.games.size() - 1)
        _selection.second = core.games.size() - 1;
}

void MainMenu::moveRight(const CoreExtension &core)
{
    if (_selection.first == SELECT_GAME)
        _selection.first = SELECT_LIB;
    if (_selection.second > core.libs.size() - 1)
        _selection.second = core.libs.size() - 1;
}

void MainMenu::primaryPressed(const CoreExtension &core)
{
    if (_selection.first == SELECT_GAME)
        core.loadGame(core.games[static_cast<size_t>(_selection.second)]);
    else if (_selection.first == SELECT_LIB)
        core.loadGraphical(core.libs[static_cast<size_t>(_selection.second)]);
}

void MainMenu::render(Arcade::IGraphicLib *)
{}

const std::string MainMenu::getLibName(const std::string &path)
{
    auto start = path.find(LIB_PREFIX) + strlen(LIB_PREFIX);

    return path.substr(start, path.find(".so") - start);
}

void MainMenu::render(Arcade::IGraphicLib *graphic, const Arcade::IMenu::CoreExtension &core)
{
    if (!graphic)
        return;
    graphic->getRenderer().clear();
    graphic->getRenderer().drawText("Games", 30, Arcade::Vector(0.25, 0.35), Arcade::Color(0, 255, 255));
    for (size_t i = 0; i < core.games.size(); i++) {
        graphic->getRenderer().drawText((getLibName(core.games[i])), 30,
                Arcade::Vector(0.25, 0.4 + static_cast<double>(i) / 20),
                (_selection.first == SELECT_GAME && _selection.second == i) ? _selectedColor : _unselectedColor);
    }
    graphic->getRenderer().drawText("Graphicals", 30, Arcade::Vector(0.55, 0.35), Arcade::Color(0, 255, 255));
    for (size_t i = 0; i < core.libs.size(); i++) {
            graphic->getRenderer().drawText(getLibName(core.libs[i]), 30,
                Arcade::Vector(0.55, 0.4 + static_cast<double>(i) / 20),
                (_selection.first == SELECT_LIB && _selection.second == i) ? _selectedColor : _unselectedColor);
    }
    graphic->getRenderer().display();
}

bool MainMenu::isCloseRequested() const noexcept
{
    return false;
}

void MainMenu::reloadResources(Arcade::IGraphicLib *)
{}
