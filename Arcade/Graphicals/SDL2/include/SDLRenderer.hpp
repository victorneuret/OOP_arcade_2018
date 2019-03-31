/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SDLRenderer.hpp
*/

#pragma once

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "IRenderer.hpp"

constexpr float WIN_WIDTH = 800;
constexpr float WIN_HEIGHT = 800;

class SDLRenderer final : public Arcade::IRenderer {
public:
    SDLRenderer();
    SDLRenderer(const SDLRenderer &copy) = delete;
    ~SDLRenderer() noexcept override;

    SDLRenderer &operator=(const SDLRenderer &copy) = delete;

    void drawRectangle(const Arcade::Rect &rect, const Arcade::Color &color, bool fill) override;
    void drawSprite(const Arcade::ASprite *sprite) override;
    void drawText(const std::string &text, uint8_t fontSize, const Arcade::Vector &pos, const Arcade::Color &color) override;

    void display() override;
    void clear() override;

private:
    SDL_Window *_window = nullptr;
    SDL_Renderer *_renderer = nullptr;
};
