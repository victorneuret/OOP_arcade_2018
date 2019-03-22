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
#include <thread>
#include <chrono>

Core::Core(const std::string &path)
    : _libs(), _games()
{
    _addExtension(std::string(GAME_PATH) + "/" + MAIN_MENU_NAME, GAME);
    _addExtension(path, GRAPHICAL);
    if (_games.empty() || _libs.empty())
        throw std::runtime_error("Failed to load core modules");
    _loadDirectory(LIB_PATH);
    _loadDirectory(GAME_PATH);
    _loadGraphical(_libs[0]);
    _loadGame(_games[0]);
}

Core::~Core()
{
    if (_loadedGame.dl) {
        delete reinterpret_cast<Arcade::IGame *>(_loadedGame.instance);
        dlclose(_loadedGame.dl);
    }
    if (_loadedLib.dl) {
        // delete reinterpret_cast<Arcade::IGraphicLib *>(_loadedLib.instance);
        dlclose(_loadedLib.dl);
    }
}

void Core::_addExtension(const std::string &path, EXT_TYPE type) noexcept
{
    std::string absPath = std::regex_replace(std::filesystem::absolute(path).string(), std::regex("\\/\\.\\/"), "/");

    if (type == GRAPHICAL && std::find(_libs.begin(), _libs.end(), absPath) == _libs.end()) {
        _libs.push_back(absPath);
    } else if (type == GAME && std::find(_games.begin(), _games.end(), absPath) == _games.end()) {
        _games.push_back(absPath);
    }
}

void Core::_loadGraphical(const std::string &path)
{
    void *func = nullptr;

    if (_loadedLib.dl) {
        // delete reinterpret_cast<Arcade::IGraphicLib *>(_loadedLib.instance);
        dlclose(_loadedLib.dl);
    }

    _loadedLib = {path, dlopen(path.c_str(), RTLD_LAZY), nullptr};
    if (!_loadedLib.dl)
        throw std::runtime_error(dlerror());
    func = dlsym(_loadedLib.dl, "getInstance");
    if (!func)
        throw std::runtime_error(dlerror());
    _loadedLib.instance = reinterpret_cast<instanceGraphicalPtr>(func)();
    if (!_loadedLib.instance)
        throw std::runtime_error("Failed to create instance for graphical: " + _loadedGame.path);
}

void Core::_loadGame(const std::string &path)
{
    void *func = nullptr;

    if (_loadedGame.dl) {
        delete reinterpret_cast<Arcade::IGame *>(_loadedGame.instance);
        dlclose(_loadedGame.dl);
    }

    _loadedGame = {path, dlopen(path.c_str(), RTLD_LAZY), nullptr};
    if (!_loadedGame.dl)
        throw std::runtime_error(dlerror());
    func = dlsym(_loadedGame.dl, "getInstance");
    if (!func)
        throw std::runtime_error(dlerror());
    _loadedGame.instance = reinterpret_cast<instanceGamePtr>(func)();
    if (!_loadedGame.instance)
        throw std::runtime_error("Failed to create instance for game: " + _loadedGame.path);
}

void Core::_loadNextGame()
{
    const auto it = std::find(_games.begin(), _games.end(), _loadedGame.path);

    if (it == _games.end())
        _loadGame(*_games.begin());
    else if (it + 1 == _games.end())
        _loadGame(*_games.begin());
    else
        _loadGame(*(it + 1));
}

void Core::_loadNextGraphical()
{
    const auto it = std::find(_libs.begin(), _libs.end(), _loadedLib.path);

    if (it == _libs.end())
        _loadGraphical(*_libs.begin());
    else if (it + 1 == _libs.end())
        _loadGraphical(*_libs.begin());
    else
        _loadGraphical(*(it + 1));
}

void Core::_loadPrevGame()
{
    const auto it = std::find(_games.begin(), _games.end(), _loadedGame.path);

    if (it == _games.end())
        _loadGame(*_games.begin());
    else if (it == _games.begin())
        _loadGame(*(_games.end() - 1));
    else
        _loadGame(*(it - 1));
}

void Core::_loadPrevGraphical()
{
    const auto it = std::find(_libs.begin(), _libs.end(), _loadedLib.path);

    if (it == _libs.end())
        _loadGraphical(*_libs.begin());
    else if (it == _libs.begin())
        _loadGraphical(*(_libs.end() - 1));
    else
        _loadGraphical(*(it - 1));
}

void Core::_restartGame()
{
    if (_loadedGame.instance)
        delete reinterpret_cast<Arcade::IGame *>(_loadedGame.instance);
    _loadedGame.instance = reinterpret_cast<instanceGamePtr>(dlsym(_loadedGame.dl, "getInstance"))();
    if (!_loadedGame.instance)
        throw std::runtime_error(dlerror());
}

void Core::_backToMenu()
{
    _loadGame(_games[0]);
}

void Core::_exit()
{
    _isCloseRequested = true;
}

void Core::loop()
{
    while (!_isCloseRequested) {
        _tick();
        _render();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 24));
    }
}

void Core::_loadDirectory(const std::string &path) noexcept
{
    const std::regex rgx("^.*/lib_arcade_\\w+.so$");

    for (const auto &f : std::filesystem::directory_iterator(path)) {
        if (std::regex_match(f.path().string(), rgx)) {
            if (path == LIB_PATH)
                _addExtension(f.path().string(), GRAPHICAL);
            else if (path == GAME_PATH)
                _addExtension(f.path().string(), GAME);
        }
    }
}

Arcade::IGraphicLib *Core::_getGraphical()
{
    if (!_loadedLib.instance)
        throw std::runtime_error("Failed to load graphical");
    return reinterpret_cast<Arcade::IGraphicLib *>(_loadedLib.instance);
}

Arcade::IGame *Core::_getGame()
{
    if (!_loadedGame.instance)
        throw std::runtime_error("Failed to load game");
    return reinterpret_cast<Arcade::IGame *>(_loadedGame.instance);
}

void Core::_tick()
{
    if (_isCloseRequested || _getGraphical()->isCloseRequested() || _getGame()->isCloseRequested())
        return _exit();

    uint8_t key = _getGraphical()->getCoreKeyState();

    for (const auto &c : _coreKeys) {
        if (c.first & key)
            (this->*c.second)();
    }
    _getGraphical()->pollEvents();
    _getGame()->tick(_getGraphical());
}

void Core::_render()
{
    if (_isCloseRequested || _getGraphical()->isCloseRequested() || _getGame()->isCloseRequested())
        return _exit();
    _getGame()->render(_getGraphical());
}