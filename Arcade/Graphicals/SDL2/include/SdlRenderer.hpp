/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SdlRenderer.hpp
*/

#pragma once

#include <string>
#include <SDL2/SDL.h>

#include "IRenderer.hpp"

class SdlRenderer final : public Arcade::IRenderer {
public:
    SdlRenderer() noexcept;
    ~SdlRenderer() noexcept;

    void drawRectangle(const Arcade::Rect &rect, const Arcade::Color &color, bool fill) override;
    void drawTexture(const std::string &imagePath, const Arcade::Vector &pos) override;
    void drawText(const std::string &text, uint8_t fontSize, const Arcade::Vector &pos, const Arcade::Color &color) override;

    void display() override;
    void clear() override;

private:
    SDL_Window *_window = nullptr;
    SDL_Renderer *_renderer = nullptr;
};
