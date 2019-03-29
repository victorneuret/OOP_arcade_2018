/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SDLTexture.cpp
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


#include "SDLTexture.hpp"

SDLTexture::SDLTexture(const void *buffer, const size_t &len, const Arcade::Color &fallbackColor)
    : ATexture(buffer, len, fallbackColor)
{
    _surface = IMG_Load("res/spritesheet.png");
}

SDL_Surface *SDLTexture::getSurface() const
{
    return _surface;
}
