/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Core.hpp
*/

#pragma once

#include <string>
#include <vector>
#include <map>

#include "IGraphicalLib.hpp"
#include "IGame.hpp"

constexpr const char * const LIB_PATH = "./lib";
constexpr const char * const GAME_PATH = "./games";
constexpr const char * const MAIN_MENU_NAME = "lib_arcade_main_menu.so";

class Core final {
public:
    enum EXT_TYPE {
        GRAPHICAL,
        GAME
    };

    explicit Core(const std::string &path);
    ~Core();
    void loop();

private:
    using instanceGamePtr = Arcade::IGame *(*)();
    using instanceGraphicalPtr =  Arcade::IGame *(*)();
    using CorePtr = void (Core::*)();

    struct Extension {
        std::string path;
        void *dl;
        void *instance;
    };

    void _loadGraphical(const std::string &path);
    void _loadGame(const std::string &path);
    void _addExtension(const std::string &path, EXT_TYPE type) noexcept;
    void _loadDirectory(const std::string &path) noexcept;
    Arcade::IGraphicLib *_getGraphical();
    Arcade::IGame *_getGame();

    void _loadNextGraphical();
    void _loadPrevGraphical();
    void _loadNextGame();
    void _loadPrevGame();
    void _restartGame();
    void _backToMenu();
    void _exit();
    void _tick();
    void _render();

    Extension _loadedLib = {"", nullptr, nullptr};
    Extension _loadedGame = {"", nullptr, nullptr};
    bool _isCloseRequested = false;
    std::vector<std::string> _libs;
    std::vector<std::string> _games;

    const std::map<uint8_t, CorePtr> _coreKeys = {
        {Arcade::IGraphicLib::PREV_GRAPHICAL_LIB, &Core::_loadPrevGraphical},
        {Arcade::IGraphicLib::NEXT_GRAPHICAL_LIB, &Core::_loadNextGraphical},
        {Arcade::IGraphicLib::PREV_GAME_LIB, &Core::_loadPrevGame},
        {Arcade::IGraphicLib::NEXT_GAME_LIB, &Core::_loadNextGame},
        {Arcade::IGraphicLib::RESTART_GAME, &Core::_restartGame},
        {Arcade::IGraphicLib::BACK_TO_MENU, &Core::_backToMenu},
        {Arcade::IGraphicLib::EXIT, &Core::_exit}
    };
};
