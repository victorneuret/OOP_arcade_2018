/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Core.hpp
*/

#pragma once

#include <string>
#include <vector>

#include "IGraphicalLib.hpp"
#include "IGame.hpp"

constexpr const char * const LIB_PATH = "./lib";
constexpr const char * const GAME_PATH = "./games";
constexpr const char * const MAIN_MENU_NAME = "lib_arcade_main_menu.so";

class Core {
public:
    typedef Arcade::IGame *(*instanceGame_ptr)();
    typedef Arcade::IGame *(*instanceGraphical_ptr)();

    typedef struct Extension {
        std::string path;
        void *dl;
        void *instance;
    } Extension_t;

    enum EXT_TYPE {
        GRAPHICAL,
        GAME
    };

    explicit Core(const std::string &path);
    ~Core();

    void loadGraphical(const std::string &path);
    void loadGame(const std::string &path);
    void addExtension(const std::string &path, EXT_TYPE type) noexcept;
    void loadDirectory(const std::string &path) noexcept;
    void loadNextGraphical();
    void loadPrevGraphical();
    void loadNextGame();
    void loadPrevGame();
    Arcade::IGraphicLib *getGraphical();
    Arcade::IGame *getGame();
    bool tick();
    void render();

private:
    Extension_t _dl_lib = {"", nullptr, nullptr};
    Extension_t  _dl_game = {"", nullptr, nullptr};
    std::vector<std::string> _libs;
    std::vector<std::string> _games;
};
