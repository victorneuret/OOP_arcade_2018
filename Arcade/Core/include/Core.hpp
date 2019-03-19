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
constexpr const char * const MAIN_MENU_NAME = "lib_arcade_main_menu.so";

class Core {
public:

    enum EXT_TYPE {
        GRAPHICAL,
        GAME
    };

    explicit Core(const std::string &);
    ~Core();

    void loadGraphical(const std::string &);
    void loadGame(const std::string &);
    void addExtension(const std::string &, EXT_TYPE) noexcept;
    void loadDirectory(const std::string &) noexcept;
    void loadNext(EXT_TYPE) noexcept;
    void loadPrev(EXT_TYPE) noexcept;

private:
    std::pair<std::string, void *> _dl_lib = {"", nullptr};
    std::pair<std::string, void *>  _dl_game = {"", nullptr};
    std::vector<std::string> _libs;
    std::vector<std::string> _games;
};
