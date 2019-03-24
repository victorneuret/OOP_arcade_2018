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
            {SDL_SCANCODE_W, UP},
            {SDL_SCANCODE_S, DOWN},
            {SDL_SCANCODE_A, LEFT},
            {SDL_SCANCODE_D, RIGHT},
            {SDL_SCANCODE_O, PRIMARY},
            {SDL_SCANCODE_P, SECONDARY},
            {SDL_SCANCODE_K, START},
            {SDL_SCANCODE_L, SELECT}
    };
    const std::unordered_map<int, CoreKey> _coreKeys = {
            {SDL_SCANCODE_LEFT,     PREV_GRAPHICAL_LIB},
            {SDL_SCANCODE_RIGHT,    NEXT_GRAPHICAL_LIB},
            {SDL_SCANCODE_DOWN,     PREV_GAME_LIB},
            {SDL_SCANCODE_UP,       NEXT_GAME_LIB},
            {SDL_SCANCODE_R,        RESTART_GAME},
            {SDL_SCANCODE_Q,        BACK_TO_MENU},
            {SDL_SCANCODE_E,        EXIT}
    };
};