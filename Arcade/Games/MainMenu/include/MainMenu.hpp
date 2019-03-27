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
#include "Graphical/ASprite.hpp"

class MainMenu final : public Arcade::IGame {
public:
    MainMenu() = default;
    MainMenu(const MainMenu &) = delete;
    ~MainMenu() override = default;

    MainMenu &operator=(const MainMenu &) = delete;

    void tick(Arcade::IGraphicLib *graphic, double deltaTime) override;
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

    std::pair<double, double> _selection{0.5, 0.5};
    double _deltaTime = 0;

    // Temporary
    Arcade::ATexture *_texture = nullptr;
    Arcade::ASprite *_pacman = nullptr;
    Arcade::ASprite *_fullSprite = nullptr;
};

