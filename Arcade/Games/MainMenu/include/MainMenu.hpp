/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** MainMenu.hpp
*/

#pragma once

#include "IGame.hpp"
#include "IGraphicalLib.hpp"

class MainMenu final : public Arcade::IGame {
public:
    MainMenu() = default;
    ~MainMenu() override = default;

    void tick() override;
    void render(Arcade::IGraphicLib *graphic) override;
    bool isCloseRequested() const noexcept override;
};

