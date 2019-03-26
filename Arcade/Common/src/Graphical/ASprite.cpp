/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** ASprite.cpp
*/

#include <Graphical/ASprite.hpp>

#include "Graphical/ASprite.hpp"
#include "Graphical/ATexture.hpp"

Arcade::ASprite::ASprite(const Arcade::ATexture *texture, const Arcade::Rect &spriteSheetRect, const Arcade::Rect &posAndSize)
    : _texture(texture), _spriteSheetRect(spriteSheetRect), _posAndSize(posAndSize)
{
}

const Arcade::ATexture *Arcade::ASprite::getTexture() const noexcept
{
    return _texture;
}

void Arcade::ASprite::setFallbackColor(const Arcade::Color &color) noexcept
{
    _fallbackColor = color;
}

const Arcade::Rect &Arcade::ASprite::getSpriteSheetRect() const
{
    return _spriteSheetRect;
}

const Arcade::Rect &Arcade::ASprite::getPosAndSize() const
{
    return _posAndSize;
}

const Arcade::Color &Arcade::ASprite::getFallbackColor() const
{
    return _fallbackColor;
}
