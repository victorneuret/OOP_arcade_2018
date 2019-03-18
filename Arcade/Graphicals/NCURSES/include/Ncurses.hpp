/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Ncurses.hpp
*/

#pragma once

#include "IGraphicalLib.hpp"
#include "NcursesRenderer.hpp"

class Ncurses : public IGraphicLib {
public:
    Ncurses() = default;
    ~Ncurses() override = default;

    uint8_t getGameKeyState() const noexcept override;
    uint8_t getCoreKeyState() const noexcept override;
    void sendGameKeyInput(GameKey input) noexcept override;
    void sendCoreKeyInput(CoreKey input) noexcept override;

    IRenderer &getRenderer() noexcept override;
    bool isCloseRequested() const noexcept override;

private:
    NcursesRenderer _render;
};

