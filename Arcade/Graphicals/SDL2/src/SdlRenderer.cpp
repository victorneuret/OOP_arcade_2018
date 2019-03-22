/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SdlRenderer.cpp
*/

#include <iostream>

#include "IGraphicalLib.hpp"
#include "SdlRenderer.hpp"

SdlRenderer::SdlRenderer()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw std::runtime_error("SDL could not initialize! SDL_Error: " + std::string(SDL_GetError()));
    _window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!_window)
        throw std::runtime_error("Window could not be created! SDL_Error: " + std::string(SDL_GetError()));
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (!_renderer)
        throw std::runtime_error("Renderer could not be created! SDL Error: " + std::string(SDL_GetError()));
}

SdlRenderer::SdlRenderer(const SdlRenderer &copy)
{
    _window = copy._window;
    _renderer = copy._renderer;
}

SdlRenderer::~SdlRenderer()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

SdlRenderer &SdlRenderer::operator=(const SdlRenderer &copy)
{
    _window = copy._window;
    _renderer = copy._renderer;
    return *this;
}

void SdlRenderer::drawRectangle(const Arcade::Rect &rect, const Arcade::Color &color, bool fill)
{
    SDL_Surface* screenSurface = SDL_GetWindowSurface(_window);
    SDL_Rect newRect = {
            static_cast<int>(rect.pos.x * screenSurface->w),
            static_cast<int>(rect.pos.y * screenSurface->h),
            static_cast<int>(rect.size.x * screenSurface->w),
            static_cast<int>(rect.size.y * screenSurface->h)
    };

    SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
    if (fill)
        SDL_RenderFillRect(_renderer, &newRect);
    else
        SDL_RenderDrawRect(_renderer, &newRect);
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
    //SDL_UpdateWindowSurface(_window);
    SDL_RenderPresent(_renderer);
}

void SdlRenderer::clear()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}
