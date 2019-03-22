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

class SDLRenderer final : public Arcade::IRenderer {
public:
    SDLRenderer();
    SDLRenderer(const SDLRenderer &copy);
    ~SDLRenderer() noexcept;

    SDLRenderer &operator=(const SDLRenderer &copy);

    void drawRectangle(const Arcade::Rect &rect, const Arcade::Color &color, bool fill) override;
    void drawTexture(const std::string &imagePath, const Arcade::Vector &pos) override;
    void drawText(const std::string &text, uint8_t fontSize, const Arcade::Vector &pos, const Arcade::Color &color) override;

    void display() override;
    void clear() override;

private:
    SDL_Window *_window = nullptr;
    SDL_Renderer *_renderer = nullptr;
};
