/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SDLSprite.cpp
*/

#include <SDL2/SDL.h>

#include "SDLSprite.hpp"
#include "SDLTexture.hpp"
#include "SDLRenderer.hpp"

SDLSprite::SDLSprite(const Arcade::ATexture *texture,
                       const Arcade::Rect &spriteSheetRect,
                       const Arcade::Rect &posAndSize)
    : ASprite(texture, spriteSheetRect, posAndSize)
{
    setTextureRect(spriteSheetRect);
    setPosAndSize(posAndSize);

}

void SDLSprite::setPosAndSize(const Arcade::Rect &posAndSize)
{
    _dstrect.x = posAndSize.pos.x * WIN_WIDTH;
    _dstrect.y = posAndSize.pos.y * WIN_HEIGHT;
    _dstrect.w = posAndSize.size.x * WIN_WIDTH;
    _dstrect.h = posAndSize.size.y * WIN_HEIGHT;
}

void SDLSprite::setTextureRect(const Arcade::Rect &newRect)
{
    const auto surface = dynamic_cast<const SDLTexture *>(_texture)->getSurface();

    _srcrect.x = static_cast<int>(newRect.pos.x);
    _srcrect.y = static_cast<int>(newRect.pos.y);

    if (newRect.size == Arcade::Vector(0, 0)) {
        _srcrect.w = surface->w;
        _srcrect.h = surface->h;
    } else {
        _srcrect.w = static_cast<int>(newRect.size.x);
        _srcrect.h = static_cast<int>(newRect.size.y);
    }
}

void SDLSprite::drawSprite(SDL_Renderer *renderer)
{
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, dynamic_cast<const SDLTexture *>(_texture)->getSurface());
    SDL_RenderCopy(renderer, texture, &_srcrect, &_dstrect);
}