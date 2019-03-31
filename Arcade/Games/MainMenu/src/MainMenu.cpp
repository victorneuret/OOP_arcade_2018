/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** MainMenu.cpp
*/

#include <string>

#include "MainMenu.hpp"

MainMenu::MainMenu()
    : _username()
{}

void MainMenu::init(Arcade::IGraphicLib *)
{}

void MainMenu::reloadResources(Arcade::IGraphicLib *)
{}

void MainMenu::tick(Arcade::IGraphicLib *, double)
{}

void MainMenu::tick(Arcade::IGraphicLib *graphic, double deltaTime, const Arcade::IMenu::CoreExtension &core)
{
    if (_time > 0 || !graphic) {
            _time -= deltaTime;
            return;
    }

    uint8_t key = graphic->getGameKeyState();

    for (const auto &c : _gameKeys) {
        if (c.first & key) {
            c.second(core);
            _time = _speed;
        }
    }
}

void MainMenu::moveUp(const CoreExtension &)
{
    if (_selection.first == SELECT_USERNAME && _username.selected) {
        if (_username.name[_selection.second] < 'Z')
            _username.name[_selection.second] += 1;
        else
            _username.name[_selection.second] = 'A';
    } else if (_selection.second >= 1)
        _selection.second -= 1;
}

void MainMenu::moveDown(const CoreExtension &core)
{
    if (_selection.first == SELECT_USERNAME && _username.selected) {
        if (_username.name[_selection.second] > 'A')
            _username.name[_selection.second] -= 1;
        else
            _username.name[_selection.second] = 'Z';
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
    else if (_selection.first == SELECT_USERNAME) {
        if (!_username.selected)
            _selection.second = 0;
        else if (_selection.second > USERNAME_LEN - 1)
            _selection.second = USERNAME_LEN - 1;
    }
}

void MainMenu::moveLeft(const CoreExtension &core)
{
    if (_selection.first == SELECT_USERNAME && _username.selected) {
        if (_selection.second > 0)
            _selection.second -= 1;
    } else if (_selection.first > 0)
        _selection.first -= 1;
    onChange(core);
}

void MainMenu::moveRight(const CoreExtension &core)
{
    if (_selection.first == SELECT_USERNAME && _username.selected) {
            _selection.second += 1;
    } else if (_selection.first < SELECT_USERNAME)
        _selection.first += 1;
    onChange(core);
}

void MainMenu::primaryPressed(const Arcade::IMenu::CoreExtension &core)
{
    if (_selection.first == SELECT_GAME)
        core.loadGame(core.games[static_cast<size_t>(_selection.second)]);
    else if (_selection.first == SELECT_LIB)
        core.loadGraphical(core.libs[static_cast<size_t>(_selection.second)]);
    else if (_selection.first == SELECT_USERNAME)
        _username.selected = !_username.selected;
}

const std::string MainMenu::getLibName(const std::string &path)
{
    auto start = path.find(LIB_PREFIX) + std::string(LIB_PREFIX).size();

    return path.substr(start, path.find(LIB_EXTENSION) - start);
}

void MainMenu::render(Arcade::IGraphicLib *graphic)
{
    graphic->getRenderer().drawText("Player", 30, Arcade::Vector(0.48, 0.08), Arcade::Color(0, 255, 255));
    for (uint8_t i = 0; i < USERNAME_LEN; i++) {
        if (_selection.first == SELECT_USERNAME && _username.selected)
            graphic->getRenderer().drawText(std::string(1, _username.name[i]), 30, Arcade::Vector(0.49 + static_cast<double>(i) / 40, 0.1),
                (_selection.first == SELECT_USERNAME && _selection.second == i && _username.selected) ? Arcade::Color(0, 255, 255) : Arcade::Color(200, 200, 200));
        else
            graphic->getRenderer().drawText(std::string(1, _username.name[i]), 30, Arcade::Vector(0.49 + static_cast<double>(i) / 40, 0.1),
                (_selection.first == SELECT_USERNAME) ? Arcade::Color(200, 200, 200) : _unselectedColor);
    }
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
    graphic->getRenderer().display();
}

bool MainMenu::isCloseRequested() const noexcept
{
    return false;
}
