/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Core.hpp
*/

#pragma once

#include <string>
#include <vector>

constexpr const char * const LIB_PATH = "./lib";
constexpr const char * const GAME_PATH = "./games";

class Core {
public:

    enum EXT_TYPE {
        LIBRARY,
        GAME
    };

    explicit Core(const std::string &);
    ~Core();

    const std::string &getLib() const noexcept {
        return _dl_lib.first;
    };

    const std::string &getGame() const noexcept {
        return _dl_game.first;
    };

    void loadLibrary(const std::string &);
    void loadGame(const std::string &);
    void loadDirectory(const std::string &);
    void loadNext(EXT_TYPE type);
    void loadPrev(EXT_TYPE type);

private:
    std::pair<std::string, void *> _dl_lib = {"", nullptr};
    std::pair<std::string, void *>  _dl_game = {"", nullptr};
    std::vector<std::string> _libs;
    std::vector<std::string> _games;
};

