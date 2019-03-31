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
            const std::vector<std::string> &games;
            const std::vector<std::string> &libs;
            const std::string &loadedLibrary;
            const std::function<void (const std::string &)> &loadGame;
            const std::function<void (const std::string &)> &loadGraphical;

            CoreExtension(const std::vector<std::string> &gameList,
                const std::vector<std::string> &libList,
                const std::string &loadedLibraryPath,
                const std::function<void (const std::string &)> &loadGamePtr,
                const std::function<void (const std::string &)> &loadGraphicalPtr) noexcept;
            ~CoreExtension() = default;
        };

        virtual ~IMenu() = default;
        virtual void tick(IGraphicLib *graphic, double deltaTime, const CoreExtension &core) = 0;
        virtual void render(IGraphicLib *graphic, const Arcade::IMenu::CoreExtension &core) = 0;
    };
}
