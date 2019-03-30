/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** IGame.hpp
*/

#pragma once

#include "IGraphicalLib.hpp"

namespace Arcade {
    class IGame {
    public:
        virtual ~IGame() = default;

        virtual void init(IGraphicLib *) = 0;
        virtual void tick(IGraphicLib *, double deltaTime) = 0;
        virtual void render(IGraphicLib *) = 0;
        virtual void reloadResources(IGraphicLib *) = 0;
        virtual bool isCloseRequested() const noexcept = 0;
    };
}
