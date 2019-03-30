/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** MainMenu.cpp
*/

#include <string.h>

#include "MainMenu.hpp"

void MainMenu::init(Arcade::IGraphicLib *)
{
}

MainMenu::MainMenu()
    : _pseudo()
{}

void MainMenu::tick(Arcade::IGraphicLib *, double)
{}

void MainMenu::tick(Arcade::IGraphicLib *graphic, double deltaTime, const Arcade::IMenu::CoreExtension &core)
{
    if (!graphic)
        return;

    _time += deltaTime;
    if (_time >= _speed) {
        uint8_t key = graphic->getGameKeyState();

        for (const auto &c : _gameKeys) {
            if (c.first & key)
                c.second(core);
        }
        _time -= _speed;
    }
}

void MainMenu::moveUp(const CoreExtension &)
{
    if (_selection.first == SELECT_PSEUDO && _pseudo.selected) {
        if (_pseudo.name[_selection.second] < 'Z')
            _pseudo.name[_selection.second] += 1;
        else
            _pseudo.name[_selection.second] = 'A';
    } else if (_selection.second >= 1)
        _selection.second -= 1;
}

void MainMenu::moveDown(const CoreExtension &core)
{
    if (_selection.first == SELECT_PSEUDO && _pseudo.selected) {
        if (_pseudo.name[_selection.second] > 'A')
            _pseudo.name[_selection.second] -= 1;
        else
            _pseudo.name[_selection.second] = 'Z';
    }
    if ((_selection.first == SELECT_GAME && _selection.second < core.games.size() - 1) ||
        (_selection.first == SELECT_LIB && _selection.second < core.libs.size() - 1))
        _selection.second += 1;
}

void MainMenu::onChange(const CoreExtension &core) noexcept
{
    if (_selection.first == SELECT_GAME && _selection.second > core.games.size() - 1)
        _selection.second = core.games.size() - 1;
    else if (_selection.first == SELECT_LIB && _selection.second > core.libs.size())
        _selection.second = core.libs.size() - 1;
    else if (_selection.first == SELECT_PSEUDO) {
        if (!_pseudo.selected)
            _selection.second = 0;
        else if (_selection.second > PSEUDO_SIZE - 1)
            _selection.second = PSEUDO_SIZE - 1;
    }
}

void MainMenu::moveLeft(const CoreExtension &core)
{
    if (_selection.first == SELECT_PSEUDO && _pseudo.selected) {
        if (_selection.second > 0)
            _selection.second -= 1;
    } else if (_selection.first > 0)
        _selection.first -= 1;
    onChange(core);
}

void MainMenu::moveRight(const CoreExtension &core)
{
    if (_selection.first == SELECT_PSEUDO && _pseudo.selected) {
            _selection.second += 1;
    } else if (_selection.first < SELECT_PSEUDO)
        _selection.first += 1;
    onChange(core);
}

void MainMenu::primaryPressed(const Arcade::IMenu::CoreExtension &core)
{
    if (_selection.first == SELECT_GAME)
        core.loadGame(core.games[static_cast<size_t>(_selection.second)]);
    else if (_selection.first == SELECT_LIB)
        core.loadGraphical(core.libs[static_cast<size_t>(_selection.second)]);
    else if (_selection.first == SELECT_PSEUDO)
        _pseudo.selected = !_pseudo.selected;
}

const std::string MainMenu::getLibName(const std::string &path)
{
    auto start = path.find(LIB_PREFIX) + strlen(LIB_PREFIX);

    return path.substr(start, path.find(".so") - start);
}

void MainMenu::render(Arcade::IGraphicLib *graphic)
{
    for (uint8_t i = 0; i < PSEUDO_SIZE; i++) {
        if (_selection.first == SELECT_PSEUDO && _pseudo.selected)
            graphic->getRenderer().drawText(std::string(1, _pseudo.name[i]), 30, Arcade::Vector(static_cast<double>(i) / 40, 0),
                (_selection.first == SELECT_PSEUDO && _selection.second == i && _pseudo.selected) ? Arcade::Color(0, 255, 255) : Arcade::Color(200, 200, 200));
        else
            graphic->getRenderer().drawText(std::string(1, _pseudo.name[i]), 30, Arcade::Vector(static_cast<double>(i) / 40, 0),
                (_selection.first == SELECT_PSEUDO) ? Arcade::Color(200, 200, 200) : _unselectedColor);
    }
}

void MainMenu::init(Arcade::IGraphicLib *)
{}

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
        if (core.loadedLibrary == core.libs[i]) {
            graphic->getRenderer().drawText(getLibName(core.libs[i]), 30,
                Arcade::Vector(0.55, 0.4 + static_cast<double>(i) / 20),
                (_selection.first == SELECT_LIB && _selection.second == i) ? Arcade::Color(0, 255, 255) : Arcade::Color(0, 180, 180));
        } else {
            graphic->getRenderer().drawText(getLibName(core.libs[i]), 30,
                Arcade::Vector(0.55, 0.4 + static_cast<double>(i) / 20),
                (_selection.first == SELECT_LIB && _selection.second == i) ? _selectedColor : _unselectedColor);
        }
    }
    render(graphic);
    graphic->getRenderer().drawText(std::to_string(_time), 30, Arcade::Vector(0.8, 0.35), Arcade::Color(0, 255, 255));
    graphic->getRenderer().display();
}

bool MainMenu::isCloseRequested() const noexcept
{
    return false;
}

void MainMenu::reloadResources(Arcade::IGraphicLib *)
{}
