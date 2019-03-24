/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** MainMenu.hpp
*/

#pragma once

#include <unordered_map>
#include <functional>

#include "IGame.hpp"
#include "IGraphicalLib.hpp"

class MainMenu final : public Arcade::IGame {
public:
    MainMenu() = default;
    ~MainMenu() override = default;

    void tick(Arcade::IGraphicLib *graphic) override;
    void render(Arcade::IGraphicLib *graphic) override;
    bool isCloseRequested() const noexcept override;
    void reloadResources(Arcade::IGraphicLib *) override;

private:
    using MainMenuPtr = void (MainMenu::*)();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void primaryPressed();

    const std::unordered_map<uint8_t, std::function<void ()>> _gameKeys = {
        {Arcade::IGraphicLib::UP, std::bind(&MainMenu::moveUp, this)},
        {Arcade::IGraphicLib::DOWN, std::bind(&MainMenu::moveDown, this)},
        {Arcade::IGraphicLib::LEFT, std::bind(&MainMenu::moveLeft, this)},
        {Arcade::IGraphicLib::RIGHT, std::bind(&MainMenu::moveRight, this)},
        {Arcade::IGraphicLib::PRIMARY, std::bind(&MainMenu::primaryPressed, this)}
    };

    std::pair<int, int> _selection{0, 0};
};

