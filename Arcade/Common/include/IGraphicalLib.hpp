/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** IGraphicalLib.hpp
*/

#pragma once

#include <cstdint>
#include <functional>

#include "IRenderer.hpp"

namespace Arcade {
    class IGraphicLib {
    public:
        enum GameKey {
            UP = (1 << 0),
            DOWN = (1 << 1),
            LEFT = (1 << 2),
            RIGHT = (1 << 3),
            PRIMARY = (1 << 4),
            SECONDARY = (1 << 5),
            START = (1 << 6),
            SELECT = (1 << 7)
        };

        enum CoreKey {
            PREV_GRAPHICAL_LIB = (1 << 0),
            NEXT_GRAPHICAL_LIB = (1 << 1),
            PREV_GAME_LIB = (1 << 2),
            NEXT_GAME_LIB = (1 << 3),
            RESTART_GAME = (1 << 4),
            BACK_TO_MENU = (1 << 5),
            EXIT = (1 << 6)
        };

        virtual ~IGraphicLib() = default;

        virtual uint8_t getGameKeyState() const noexcept = 0;
        virtual uint8_t getCoreKeyState() const noexcept = 0;
        virtual void sendGameKeyInput(GameKey input) noexcept = 0;
        virtual void sendCoreKeyInput(CoreKey input) noexcept = 0;
        virtual void pollEvents() = 0;

        virtual ATexture *createTexture(const void *buffer, const size_t &len, const Arcade::Color &fallbackColor) = 0;
        virtual ASprite *createSprite(const ATexture *texture, const Rect &spriteSheetRect, const Rect &posAndSize) = 0;

        virtual IRenderer &getRenderer() noexcept = 0;
        virtual bool isCloseRequested() const noexcept = 0;
    };
}
