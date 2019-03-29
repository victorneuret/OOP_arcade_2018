/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Ncurses.hpp
*/

#pragma once

#include <unordered_map>
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
    void pollEvents() override;

    Arcade::ATexture *createTexture(const void *buffer, const size_t &len) override;
    Arcade::ASprite *createSprite(const Arcade::ATexture *texture, const Arcade::Rect &spriteSheetRect,
                                  const Arcade::Rect &posAndSize) override;

    Arcade::IRenderer &getRenderer() noexcept override;
    bool isCloseRequested() const noexcept override;

private:
    NcursesRenderer _render;
    int _key = 0;

    const std::unordered_map<int, Arcade::IGraphicLib::GameKey> _gameKeys = {
        {KEY_UP,    UP},
        {KEY_DOWN,  DOWN},
        {KEY_LEFT,  LEFT},
        {KEY_RIGHT, RIGHT},
        {'x',       PRIMARY},
        {'c',       SECONDARY},
        {'b',       START},
        {'n',       SELECT}
    };
    const std::unordered_map<int, Arcade::IGraphicLib::CoreKey> _coreKeys = {
        {KEY_F(1), PREV_GRAPHICAL_LIB},
        {KEY_F(2), NEXT_GRAPHICAL_LIB},
        {KEY_F(3), PREV_GAME_LIB},
        {KEY_F(4), NEXT_GAME_LIB},
        {KEY_F(5), RESTART_GAME},
        {27,       BACK_TO_MENU},
        {KEY_F(9), EXIT}
    };
};
