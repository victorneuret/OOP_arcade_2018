/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SDLTexture.cpp
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "SDLTexture.hpp"

SDLTexture::SDLTexture(const void *buffer, const size_t &len)
    : ATexture(buffer, len)
{
    SDL_RWops *rw = SDL_RWFromMem(const_cast<void *>(buffer), static_cast<int>(len));
    _surface = IMG_Load_RW(rw, 1);
}

SDLTexture::~SDLTexture()
{
    SDL_FreeSurface(_surface);
}

SDL_Surface *SDLTexture::getSurface() const
{
    return _surface;
}
