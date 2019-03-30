/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Core.cpp
*/

#include <string>
#include <dlfcn.h>
#include <stdexcept>
#include <filesystem>
#include <iostream>
#include <regex>
#include <algorithm>
#include <unistd.h>

#include "Core.hpp"
#include "IMenu.hpp"

Core::Core(const std::string &path)
    : _libs(), _games()
{
    _addExtension(path, GRAPHICAL);
    if (_libs.empty())
        throw std::runtime_error("Failed to load core modules");
    _loadDirectory(LIB_PATH);
    _loadDirectory(GAME_PATH);
    _loadGraphical(_libs[0]);
    _loadGame(MAIN_MENU_PATH);
}

Core::~Core()
{
    if (_loadedGame.dl) {
        delete reinterpret_cast<Arcade::IGame *>(_loadedGame.instance);
        dlclose(_loadedGame.dl);
    }
    if (_loadedLib.dl) {
         delete reinterpret_cast<Arcade::IGraphicLib *>(_loadedLib.instance);
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
    if (path == _loadedLib.path)
        return;

    if (_loadedLib.dl) {
        delete reinterpret_cast<Arcade::IGraphicLib *>(_loadedLib.instance);
        dlclose(_loadedLib.dl);
    }

    _loadedLib = {path, dlopen(path.c_str(), RTLD_LAZY), nullptr};
    if (!_loadedLib.dl)
        throw std::runtime_error(dlerror());

    std::function<Arcade::IGraphicLib *()> func = reinterpret_cast<InstanceGraphicalPtr>
        (dlsym(_loadedLib.dl, "getGraphicalInstance"));

    if (!func)
        throw std::runtime_error(dlerror());
    _loadedLib.instance = func();
    if (!_loadedLib.instance)
        throw std::runtime_error("Failed to create instance for graphical: " + _loadedGame.path);

    auto game = _getGame();
    auto graphical = _getGraphical();

    if (game != nullptr && graphical != nullptr) {
        game->reloadResources(graphical);
        throw std::runtime_error("Failed to create instance for graphical: " + _loadedLib.path);
    }
}

void Core::_loadGame(const std::string &path)
{
    if (_loadedGame.dl) {
        delete reinterpret_cast<Arcade::IGame *>(_loadedGame.instance);
        dlclose(_loadedGame.dl);
    }

    _loadedGame = {path, dlopen(path.c_str(), RTLD_LAZY), nullptr};
    if (!_loadedGame.dl)
        throw std::runtime_error(dlerror());

    std::function<Arcade::IGame *()> func = reinterpret_cast<InstanceGamePtr>
        (dlsym(_loadedGame.dl, "getGameInstance"));

    if (!func)
        throw std::runtime_error(dlerror());
    _loadedGame.instance = func();
    if (!_loadedGame.instance)
        throw std::runtime_error("Failed to create instance for game: " + _loadedGame.path);

    auto game = _getGame();
    auto graphical = _getGraphical();

    if (game != nullptr && graphical != nullptr)
        game->init(graphical);
}

void Core::_loadNextGame()
{
    if (_loadedGame.path == MAIN_MENU_PATH)
        return;

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
    if (_loadedGame.path == MAIN_MENU_PATH)
        return;

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

    std::function<Arcade::IGame *()> func = reinterpret_cast<InstanceGamePtr>
        (dlsym(_loadedGame.dl, "getGameInstance"));

    if (!func)
        throw std::runtime_error(dlerror());
    _loadedGame.instance = func();
    if (!_loadedGame.instance)
        throw std::runtime_error(dlerror());

    auto game = _getGame();
    auto graphical = _getGraphical();

    if (game != nullptr && graphical != nullptr)
        game->init(graphical);
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
    auto start = std::chrono::system_clock::now();

    _getGame()->init(_getGraphical());

    while (!_shouldExit()) {
        start = std::chrono::system_clock::now();

        _tick();
        _render();

        _deltaTime = (std::chrono::system_clock::now() - start).count();
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

Arcade::IGraphicLib *Core::_getGraphical() const
{
    if (!_loadedLib.instance)
        return nullptr;
    return reinterpret_cast<Arcade::IGraphicLib *>(_loadedLib.instance);
}

Arcade::IGame *Core::_getGame() const
{
    if (!_loadedGame.instance)
        return nullptr;
    return reinterpret_cast<Arcade::IGame *>(_loadedGame.instance);
}

void Core::_tickMainMenu() noexcept
{
    dynamic_cast<Arcade::IMenu *>(_getGame())->tick(_getGraphical(), _deltaTime,
        Arcade::IMenu::CoreExtension(_games, _libs, _loadedLib.path, std::bind(&Core::_loadGame, this, std::placeholders::_1),
            std::bind(&Core::_loadGraphical, this, std::placeholders::_1)));
}

void Core::_renderMainMenu() noexcept
{
    dynamic_cast<Arcade::IMenu *>(_getGame())->render(_getGraphical(),
        Arcade::IMenu::CoreExtension(_games, _libs, _loadedLib.path, std::bind(&Core::_loadGame, this, std::placeholders::_1),
            std::bind(&Core::_loadGraphical, this, std::placeholders::_1)));
}

void Core::_tick()
{
    if (_shouldExit())
        return _exit();

    _getGraphical()->pollEvents();

    if (_loadedGame.path == MAIN_MENU_PATH) {
        _tickMainMenu();
    } else
        _getGame()->tick(_getGraphical(), _deltaTime);

    uint8_t key = _getGraphical()->getCoreKeyState();

    for (const auto &c : _coreKeys) {
        if (c.first & key)
            c.second();
    }
}

void Core::_render()
{
    if (_shouldExit())
        return _exit();
    if (_loadedGame.path == MAIN_MENU_PATH)
        _renderMainMenu();
    else
        _getGame()->render(_getGraphical());
}

bool Core::_shouldExit() const
{
    return (_isCloseRequested || _getGraphical()->isCloseRequested() || _getGame()->isCloseRequested());
}
