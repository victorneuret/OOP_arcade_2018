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

Core::Core(const std::string &path)
    : _libs(), _games()
{
    addExtension(path, GRAPHICAL);
    loadGraphical(_libs[0]);
}

Core::~Core()
{
    if (_dl_lib.second)
        dlclose(_dl_lib.second);
    if (_dl_game.second)
        dlclose(_dl_game.second);
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
    if (_dl_lib.second)
        dlclose(_dl_lib.second);
    _dl_lib = {path, dlopen(path.c_str(), RTLD_LAZY)};
    if (!_dl_lib.second)
        throw std::runtime_error("Failed to load library " + path);
}

void Core::loadGame(const std::string &path)
{
    if (_dl_game.second)
        dlclose(_dl_game.second);
    _dl_game = {path, dlopen(path.c_str(), RTLD_LAZY)};
    if (!_dl_game.second)
        throw std::runtime_error("Failed to load game " + path);
}

void Core::loadNext(EXT_TYPE type) noexcept
{
    if (type == GRAPHICAL && _libs.size() > 1) {
        const auto it = std::find(_libs.begin(), _libs.end(), _dl_lib.first);
        if (it == _libs.end())
           loadGraphical(*_libs.begin());
        else if (it + 1 == _libs.end())
            loadGraphical(*_libs.begin());
        else
            loadGraphical(*(it + 1));
    } else if (type == GAME && _games.size() > 1) {
        const auto it = std::find(_games.begin(), _games.end(), _dl_game.first);
        if (it == _games.end())
            loadGame(*_games.begin());
        else if (it + 1 == _games.end())
            loadGame(*_games.begin());
        else
            loadGame(*(it + 1));
    }
}

void Core::loadPrev(EXT_TYPE type) noexcept
{
    if (type == GRAPHICAL && _libs.size() > 1) {
        const auto it = std::find(_libs.begin(), _libs.end(), _dl_lib.first);
        if (it == _libs.end())
            loadGraphical(*_libs.begin());
        else if (it == _libs.begin())
            loadGraphical(*(_libs.end() - 1));
        else
            loadGraphical(*(it - 1));
    } else if (type == GAME && _games.size() > 1) {
        const auto it = std::find(_games.begin(), _games.end(), _dl_game.first);
        if (it == _games.end())
            loadGame(*_games.begin());
        else if (it == _games.begin())
            loadGame(*(_games.end() - 1));
        else
            loadGame(*(it - 1));
    }
}

void Core::loadDirectory(const std::string &path) noexcept
{
    const std::regex rgx("^.*/lib_arcade_\\w+.so$");

    for (const auto &f: std::filesystem::directory_iterator(path)) {
        if (std::regex_match(f.path().string(), rgx)) {
            if (path == LIB_PATH)
                addExtension(f.path().string(), GRAPHICAL);
            else if (path == GAME_PATH)
                addExtension(f.path().string(), GAME);
        }
    }
}