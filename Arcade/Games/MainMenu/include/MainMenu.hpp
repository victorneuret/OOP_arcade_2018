/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** MainMenu.hpp
*/

#pragma once

#include <map>

#include "IGame.hpp"
#include "IGraphicalLib.hpp"

class MainMenu final : public Arcade::IGame {
public:
    MainMenu() {
        INDEX++;
    };
    ~MainMenu() override = default;

    void tick(Arcade::IGraphicLib *graphic) override;
    void render(Arcade::IGraphicLib *graphic) override;
    bool isCloseRequested() const noexcept override;

private:
    using MainMenuPtr = void (MainMenu::*)();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void primaryPressed();

    const std::map<uint8_t, MainMenuPtr> _gameKeys = {
        {Arcade::IGraphicLib::UP, &MainMenu::moveUp},
        {Arcade::IGraphicLib::DOWN, &MainMenu::moveDown},
        {Arcade::IGraphicLib::LEFT, &MainMenu::moveLeft},
        {Arcade::IGraphicLib::RIGHT, &MainMenu::moveRight},
        {Arcade::IGraphicLib::PRIMARY, &MainMenu::primaryPressed}
    };

    std::pair<uint8_t, uint8_t> _selection = {0, 0};
    static int INDEX;
};

