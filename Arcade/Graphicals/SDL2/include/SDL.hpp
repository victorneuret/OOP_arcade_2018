/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SDL.hpp
*/

#pragma once

#include <SDL2/SDL.h>
#include <unordered_map>

#include "IGraphicalLib.hpp"
#include "SDLRenderer.hpp"

class SDL final : public Arcade::IGraphicLib {
public:
    SDL();
    ~SDL() override = default;

    uint8_t getGameKeyState() const noexcept override;
    uint8_t getCoreKeyState() const noexcept override;
    void sendGameKeyInput(GameKey input) noexcept override;
    void sendCoreKeyInput(CoreKey input) noexcept override;
    Arcade::IRenderer &getRenderer() noexcept override;
    bool isCloseRequested() const noexcept override;
    void pollEvents() override;

private:
    SDLRenderer _renderer;
    bool _closeRequested = false;
    const std::unordered_map<int, GameKey> _gameKeys = {
            {'z', UP},
            {'s', DOWN},
            {'q', LEFT},
            {'d', RIGHT},
            {'o', PRIMARY},
            {'p', SECONDARY},
            {'k', START},
            {'l', SELECT}
    };
    const std::unordered_map<int, CoreKey> _coreKeys = {
            {SDLK_LEFT,     PREV_GRAPHICAL_LIB},
            {SDLK_RIGHT,    NEXT_GRAPHICAL_LIB},
            {SDLK_DOWN,     PREV_GAME_LIB},
            {SDLK_RIGHT,    NEXT_GAME_LIB},
            {'r',           RESTART_GAME},
            {'a',           BACK_TO_MENU},
            {'e',           EXIT}
    };
};