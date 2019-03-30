/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SDLRenderer.cpp
*/

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "IGraphicalLib.hpp"
#include "SDLRenderer.hpp"
#include "SDLSprite.hpp"

SDLRenderer::SDLRenderer()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw std::runtime_error("SDL could not initialize! SDL_Error: " + std::string(SDL_GetError()));

    _window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!_window)
        throw std::runtime_error("Window could not be created! SDL_Error: " + std::string(SDL_GetError()));

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (!_renderer)
        throw std::runtime_error("Renderer could not be created! SDL Error: " + std::string(SDL_GetError()));

    TTF_Init();
    IMG_Init(IMG_INIT_PNG);
}

SDLRenderer::~SDLRenderer() noexcept
{
    TTF_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void SDLRenderer::drawRectangle(const Arcade::Rect &rect, const Arcade::Color &color, bool fill)
{
    SDL_Surface *screenSurface = SDL_GetWindowSurface(_window);
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

void SDLRenderer::drawSprite(const Arcade::ASprite *sprite)
{
    const auto &sdlSprite = dynamic_cast<const SDLSprite *>(sprite);
    const_cast<SDLSprite *>(sdlSprite)->drawSprite(_renderer);
}

void SDLRenderer::drawText(const std::string &text, uint8_t fontSize, const Arcade::Vector &pos, const Arcade::Color &color)
{
    int textureWidth = 0;
    int textureHeight = 0;
    SDL_Rect textureRect;

    SDL_Surface *screenSurface = SDL_GetWindowSurface(_window);

    TTF_Font *font = TTF_OpenFont("res/arcade.ttf", fontSize);
    if (!font)
        throw std::runtime_error(std::string(TTF_GetError()));
    SDL_Color fontColor = {color.r, color.g, color.b, color.a};

    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), fontColor);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);

    SDL_QueryTexture(texture, nullptr, nullptr, &textureWidth, &textureHeight);
    textureRect = {
            static_cast<int>(pos.x * screenSurface->w),
            static_cast<int>(pos.y * screenSurface->h),
            textureWidth,
            textureHeight
    };

    SDL_RenderCopy(_renderer, texture, nullptr, &textureRect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
}

void SDLRenderer::display()
{
    SDL_RenderPresent(_renderer);
}

void SDLRenderer::clear()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}
