/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SdlRenderer.cpp
*/

#include <iostream>

#include "IGraphicalLib.hpp"
#include "SdlRenderer.hpp"

SdlRenderer::SdlRenderer() noexcept
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::runtime_error("SDL could not initialize! SDL_Error: " + std::string(SDL_GetError()));
    else {
        _window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
        if (!_window)
            throw std::runtime_error("Window could not be created! SDL_Error: " + std::string(SDL_GetError()));
        _renderer = SDL_CreateRenderer(_window, -1, 0);
        if (!_renderer)
            throw std::runtime_error("Renderer could not be created! SDL Error: " + std::string(SDL_GetError()));
        SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_Surface* screenSurface = SDL_GetWindowSurface(_window);
        SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
        SDL_RenderPresent(_renderer);
    }
}

SdlRenderer::~SdlRenderer()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void SdlRenderer::drawRectangle(const Arcade::Rect &rect, const Arcade::Color &color, bool fill)
{
    SDL_Rect newRect = {
            (int) rect.pos.x,
            (int) rect.pos.y,
            (int) rect.size.x,
            (int) rect.size.y
    };

    SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(_renderer, &newRect);
    SDL_RenderPresent(_renderer);
}

void SdlRenderer::drawTexture(const std::string &, const Arcade::Vector &)
{
}

void SdlRenderer::drawText(const std::string &, uint8_t, const Arcade::Vector &, const Arcade::Color &)
{
}

void SdlRenderer::display()
{
    //SDL_Surface* screenSurface = SDL_GetWindowSurface(_window);
    //SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
    SDL_UpdateWindowSurface(_window);
}

void SdlRenderer::clear()
{}
