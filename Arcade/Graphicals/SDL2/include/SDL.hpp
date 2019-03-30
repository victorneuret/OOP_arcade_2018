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

    void pollEvents() override;
    Arcade::ATexture *createTexture(const void *buffer, const size_t &len) override;
    Arcade::ASprite *createSprite(const Arcade::ATexture *texture, const Arcade::Rect &spriteSheetRect,
                                  const Arcade::Rect &posAndSize) override;

    Arcade::IRenderer &getRenderer() noexcept override;
    bool isCloseRequested() const noexcept override;

private:
    SDLRenderer _renderer;
    bool _closeRequested = false;
    const std::unordered_map<int, GameKey> _gameKeys = {
        {SDL_SCANCODE_UP,    UP},
        {SDL_SCANCODE_DOWN,  DOWN},
        {SDL_SCANCODE_LEFT,  LEFT},
        {SDL_SCANCODE_RIGHT, RIGHT},
        {SDL_SCANCODE_X,     PRIMARY},
        {SDL_SCANCODE_C,     SECONDARY},
        {SDL_SCANCODE_B,     START},
        {SDL_SCANCODE_N,     SELECT}
    };
    const std::unordered_map<int, CoreKey> _coreKeys = {
        {SDL_SCANCODE_F1,     PREV_GRAPHICAL_LIB},
        {SDL_SCANCODE_F2,     NEXT_GRAPHICAL_LIB},
        {SDL_SCANCODE_F3,     PREV_GAME_LIB},
        {SDL_SCANCODE_F4,     NEXT_GAME_LIB},
        {SDL_SCANCODE_F5,     RESTART_GAME},
        {SDL_SCANCODE_ESCAPE, BACK_TO_MENU},
        {SDL_SCANCODE_F9,     EXIT}
    };
};