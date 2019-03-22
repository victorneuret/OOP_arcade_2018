/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Ncurses.hpp
*/

#pragma once

#include <map>
#include <ncurses.h>

#include "IGraphicalLib.hpp"
#include "NcursesRenderer.hpp"

class Ncurses final : public Arcade::IGraphicLib {
public:
    Ncurses();
    ~Ncurses() override = default;

    uint8_t getGameKeyState() const noexcept override;
    uint8_t getCoreKeyState() const noexcept override;
    void sendGameKeyInput(GameKey input) noexcept override;
    void sendCoreKeyInput(CoreKey input) noexcept override;
    Arcade::IRenderer &getRenderer() noexcept override;
    bool isCloseRequested() const noexcept override;
    void pollEvents() override;

private:
    NcursesRenderer _render;
    const std::map<int, Arcade::IGraphicLib::GameKey> _gameKeys = {
        {'z', UP},
        {'s', DOWN},
        {'q', LEFT},
        {'d', RIGHT},
        {'o', PRIMARY},
        {'p', SECONDARY},
        {'k', START},
        {'l', SELECT}
    };
    const std::map<int, Arcade::IGraphicLib::CoreKey> _coreKeys = {
        {'b',    PREV_GRAPHICAL_LIB},
        {'n',   NEXT_GRAPHICAL_LIB},
        {'c',   PREV_GAME_LIB},
        {'v',   NEXT_GAME_LIB},
        {'r',   RESTART_GAME},
        {'a',   BACK_TO_MENU},
        {'e',   EXIT}
    };
};
