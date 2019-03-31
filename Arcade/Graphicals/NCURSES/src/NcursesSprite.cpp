/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** NcursesSprite.cpp
*/

#include "NcursesSprite.hpp"

NcursesSprite::NcursesSprite(const Arcade::ATexture *texture, const Arcade::Rect &spriteSheetRect, const Arcade::Rect &posAndSize)
    : ASprite(texture, spriteSheetRect, posAndSize)
{}

void NcursesSprite::setPosAndSize(const Arcade::Rect &posAndSize)
{
    _posAndSize = posAndSize;
}

void NcursesSprite::setTextureRect(const Arcade::Rect &spriteSheetRect)
{
    _spriteSheetRect = spriteSheetRect;
}