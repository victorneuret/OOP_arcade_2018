/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** ASprite.cpp
*/

#include <Graphical/ASprite.hpp>

#include "Graphical/ASprite.hpp"

Arcade::ASprite::ASprite(const std::shared_ptr<ATexture> &texture, const Vector &pos, const Rect &rect)
    : _texture(texture), _pos(pos), _rect(rect)
{}

const std::shared_ptr<Arcade::ATexture> &Arcade::ASprite::getTexture() const noexcept
{
    return _texture;
}
