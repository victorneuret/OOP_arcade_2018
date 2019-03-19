/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Core.cpp
*/

#include "Core.hpp"

#include <string>
#include <dlfcn.h>
#include <stdexcept>
#include <filesystem>
#include <iostream>
#include <regex>
#include <algorithm>
#include <unistd.h>

Core::Core(const std::string &path)
    : _libs(), _games()
{
    addExtension(std::string(GAME_PATH) + "/" + MAIN_MENU_NAME, GAME);
    addExtension(path, GRAPHICAL);
    if (_games.empty() || _libs.empty())
        throw std::runtime_error("Failed to load core modules");
    loadGraphical(_libs[0]);
    loadGame(_games[0]);
}

Core::~Core()
{
    if (_dl_lib.dl)
        dlclose(_dl_lib.dl);
    if (_dl_game.dl)
        dlclose(_dl_game.dl);
}

void Core::addExtension(const std::string &path, EXT_TYPE type) noexcept
{
    std::string absPath = std::regex_replace(std::filesystem::absolute(path).string(), std::regex("\\/\\.\\/"), "/");

    if (type == GRAPHICAL && std::find(_libs.begin(), _libs.end(), absPath) == _libs.end()) {
        _libs.push_back(absPath);
    } else if (type == GAME && std::find(_games.begin(), _games.end(), absPath) == _games.end()) {
        _games.push_back(absPath);
    }
}

void Core::loadGraphical(const std::string &path)
{
    if (_dl_lib.dl) {
        dlclose(_dl_lib.dl);
        delete reinterpret_cast<Arcade::IGraphicLib *>(_dl_lib.instance);
    }

    _dl_lib = {path, dlopen(path.c_str(), RTLD_LAZY), nullptr};
    if (!_dl_lib.dl)
        throw std::runtime_error(dlerror());
    _dl_lib.instance = reinterpret_cast<instanceGraphical_ptr>(dlsym(_dl_lib.dl, "getInstance"))();
    if (!_dl_lib.instance)
        throw std::runtime_error(dlerror());
}

void Core::loadGame(const std::string &path)
{
    if (_dl_game.dl) {
        dlclose(_dl_game.dl);
        delete reinterpret_cast<Arcade::IGame *>(_dl_game.instance);
    }

    _dl_game = {path, dlopen(path.c_str(), RTLD_LAZY), nullptr};
    if (!_dl_game.dl)
        throw std::runtime_error(dlerror());
    _dl_game.instance = reinterpret_cast<instanceGame_ptr>(dlsym(_dl_game.dl, "getInstance"))();
    if (!_dl_game.instance)
        throw std::runtime_error(dlerror());
}

void Core::loadNextGame()
{
    const auto it = std::find(_games.begin(), _games.end(), _dl_game.path);

    if (it == _games.end())
        loadGame(*_games.begin());
    else if (it + 1 == _games.end())
        loadGame(*_games.begin());
    else
        loadGame(*(it + 1));
}

void Core::loadNextGraphical()
{
    const auto it = std::find(_libs.begin(), _libs.end(), _dl_lib.path);

    if (it == _libs.end())
       loadGraphical(*_libs.begin());
    else if (it + 1 == _libs.end())
        loadGraphical(*_libs.begin());
    else
        loadGraphical(*(it + 1));
}

void Core::loadPrevGame()
{
    const auto it = std::find(_games.begin(), _games.end(), _dl_game.path);

    if (it == _games.end())
        loadGame(*_games.begin());
    else if (it == _games.begin())
        loadGame(*(_games.end() - 1));
    else
        loadGame(*(it - 1));
}

void Core::loadPrevGraphical()
{
    const auto it = std::find(_libs.begin(), _libs.end(), _dl_lib.path);

    if (it == _libs.end())
        loadGraphical(*_libs.begin());
    else if (it == _libs.begin())
        loadGraphical(*(_libs.end() - 1));
    else
        loadGraphical(*(it - 1));
}

void Core::loadDirectory(const std::string &path) noexcept
{
    const std::regex rgx("^.*/lib_arcade_\\w+.so$");

    for (const auto &f : std::filesystem::directory_iterator(path)) {
        if (std::regex_match(f.path().string(), rgx)) {
            if (path == LIB_PATH)
                addExtension(f.path().string(), GRAPHICAL);
            else if (path == GAME_PATH)
                addExtension(f.path().string(), GAME);
        }
    }
}

Arcade::IGraphicLib *Core::getGraphical()
{
    return reinterpret_cast<Arcade::IGraphicLib *>(_dl_lib.instance);
}

Arcade::IGame *Core::getGame()
{
    return reinterpret_cast<Arcade::IGame *>(_dl_game.instance);
}

bool Core::tick()
{
    return true;
}

void Core::render()
{
    getGame()->tick();
    getGame()->render(getGraphical());
    usleep(20000);
}