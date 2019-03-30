/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SDLTexture.hpp
*/

#pragma once

#include <SDL2/SDL.h>

#include "Graphical/ATexture.hpp"

class SDLTexture : public Arcade::ATexture {
public:
    SDLTexture(const void *buffer, const size_t &len, const Arcade::Color &fallbackColor);
    ~SDLTexture() override;
    SDLTexture(const SDLTexture&) = delete;

    SDLTexture &operator=(const SDLTexture&) = delete;

    SDL_Surface *getSurface() const;

private:
    SDL_Surface *_surface = nullptr;
};

