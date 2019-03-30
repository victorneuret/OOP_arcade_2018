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

        virtual void init(IGraphicLib *graphic) = 0;
        virtual void tick(IGraphicLib *graphic, double deltaTime) = 0;
        virtual void render(IGraphicLib *graphic) = 0;
        virtual void reloadResources(IGraphicLib *graphic) = 0;
        virtual bool isCloseRequested() const noexcept = 0;
    };
}
