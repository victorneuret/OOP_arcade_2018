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
    const std::map<int, uint8_t> _gameKeys = {
        {'z', UP},
        {'s', DOWN},
        {'q', LEFT},
        {'d', RIGHT},
        {'o', PRIMARY},
        {'p', SECONDARY},
        {'k', START},
        {'l', SELECT}
    };
    const std::map<int, uint8_t> _coreKeys = {
        {KEY_LEFT,  PREV_GRAPHICAL_LIB},
        {KEY_RIGHT, NEXT_GRAPHICAL_LIB},
        {KEY_DOWN,  PREV_GAME_LIB},
        {KEY_UP,    NEXT_GAME_LIB},
        {'r',       RESTART_GAME},
        {'q',       BACK_TO_MENU},
        {'e',       EXIT}
    };
};
