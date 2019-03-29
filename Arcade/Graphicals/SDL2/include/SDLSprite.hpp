/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SDLSprite.hpp
*/

#pragma once

#include <SDL2/SDL.h>

#include "Graphical/ASprite.hpp"

class SDLSprite : public Arcade::ASprite {
public:
    SDLSprite(const Arcade::ATexture *texture, const Arcade::Rect &spriteSheetRect, const Arcade::Rect &posAndSize);
    ~SDLSprite() override = default;
    SDLSprite(const SDLSprite&) = delete;

    SDLSprite &operator=(const SDLSprite&) = delete;

    SDLSprite(const ASprite &sprite) = delete;
    ASprite &operator=(const ASprite &sprite) override = delete;

    void setPosAndSize(const Arcade::Rect &posAndSize) override;
    void setTextureRect(const Arcade::Rect &newRect) override;

    void drawSprite(SDL_Renderer *renderer);
private:
    SDL_Rect _srcrect = {0, 0, 0, 0};
    SDL_Rect _dstrect = {0, 0, 0, 0};
};
