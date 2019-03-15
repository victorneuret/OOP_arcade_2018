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
    _libs.push_back(std::filesystem::absolute(path));
    loadLibrary(_libs[0]);
}

Core::~Core()
{
    if (_dl_lib.second)
        dlclose(_dl_lib.second);
    if (_dl_game.second)
        dlclose(_dl_game.second);
}

void Core::loadLibrary(const std::string &path)
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

void Core::loadNext(EXT_TYPE type)
{
    if (type == LIBRARY && _libs.size() > 1) {
        const auto it = std::find(_libs.begin(), _libs.end(), _dl_lib.first);
        if (it == _libs.end())
           loadLibrary(*_libs.begin());
        else if (it + 1 == _libs.end())
            loadLibrary(*_libs.begin());
        else
            loadLibrary(*(it + 1));
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

void Core::loadPrev(EXT_TYPE type)
{
    if (type == LIBRARY && _libs.size() > 1) {
        const auto it = std::find(_libs.begin(), _libs.end(), _dl_lib.first);
        if (it == _libs.end())
            loadLibrary(*_libs.begin());
        else if (it == _libs.begin())
            loadLibrary(*(_libs.end() - 1));
        else
            loadLibrary(*(it - 1));
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

void Core::loadDirectory(const std::string &path)
{
    const std::regex rgx("^.*/lib_arcade_\\w+.so$");

    for (const auto &f: std::filesystem::directory_iterator(path)) {
        const std::string absPath = std::filesystem::absolute(f.path().string());

        if (std::regex_match(absPath, rgx)) {
            if (path == LIB_PATH && std::find(_libs.begin(), _libs.end(), absPath) == _libs.end()) {
                _libs.push_back(absPath);
            } else if (path == GAME_PATH && std::find(_games.begin(), _games.end(), absPath) == _games.end()) {
                _games.push_back(absPath);
            }
        }
    }
}