/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** IMenu.hpp
*/

#include <vector>
#include <string>
#include <functional>

#include "IGame.hpp"

#pragma once

namespace Arcade {
    class IMenu : public virtual IGame {
    public:
        struct CoreExtension {
            std::vector<std::string> games;
            std::vector<std::string> libs;
            std::function<void (const std::string &)> loadGame;
            std::function<void (const std::string &)> loadGraphical;
        };

        virtual ~IMenu() = default;
        virtual void tick(IGraphicLib *graphic, double deltaTime) override = 0;
        virtual void tick(IGraphicLib *graphic, double deltaTime, const CoreExtension &core) = 0;
        virtual void render(IGraphicLib *graphic) override = 0;
        virtual void render(IGraphicLib *graphic, const Arcade::IMenu::CoreExtension &core) = 0;
    };
}
