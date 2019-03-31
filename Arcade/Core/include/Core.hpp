/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Core.hpp
*/

#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

#include "IMenu.hpp"
#include "IGraphicalLib.hpp"
#include "IGame.hpp"

constexpr const char * const LIB_PATH = "./lib";
constexpr const char * const GAME_PATH = "./games";
constexpr const char * const MAIN_MENU_PATH = "./menu/lib_arcade_main_menu.so";

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
    using InstanceGamePtr = Arcade::IGame *(*)();
    using InstanceGraphicalPtr = Arcade::IGraphicLib *(*)();

    struct Extension {
        std::string path;
        void *dl;
        void *instance;
    };

    void _addExtension(const std::string &path, EXT_TYPE type) noexcept;
    void _loadDirectory(const std::string &path) noexcept;
    Arcade::IGraphicLib *_getGraphical() const;
    Arcade::IGame *_getGame() const;
    bool _shouldExit() const;
    void _tickMainMenu() noexcept;
    void _renderMainMenu() noexcept;
    void _loadGame(const std::string &path);
    void _loadGraphical(const std::string &path);

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
    Extension _loadedMenu = {"", nullptr, nullptr};
    bool _isCloseRequested = false;
    std::vector<std::string> _libs;
    std::vector<std::string> _games;

    double _deltaTime = 0;

    const std::unordered_map<uint8_t, std::function<void ()>> _coreKeys = {
        {Arcade::IGraphicLib::PREV_GRAPHICAL_LIB, std::bind(&Core::_loadPrevGraphical, this)},
        {Arcade::IGraphicLib::NEXT_GRAPHICAL_LIB, std::bind(&Core::_loadNextGraphical, this)},
        {Arcade::IGraphicLib::PREV_GAME_LIB, std::bind(&Core::_loadPrevGame, this)},
        {Arcade::IGraphicLib::NEXT_GAME_LIB, std::bind(&Core::_loadNextGame, this)},
        {Arcade::IGraphicLib::RESTART_GAME, std::bind(&Core::_restartGame, this)},
        {Arcade::IGraphicLib::BACK_TO_MENU, std::bind(&Core::_backToMenu, this)},
        {Arcade::IGraphicLib::EXIT, std::bind(&Core::_exit, this)}
    };
};
