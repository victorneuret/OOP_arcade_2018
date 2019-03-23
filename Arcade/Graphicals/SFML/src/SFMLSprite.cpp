/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SFMLSprite.cpp
*/

#include <SFMLSprite.hpp>

#include "SFMLSprite.hpp"
#include "SFMLTexture.hpp"

SFMLSprite::SFMLSprite(const std::shared_ptr<Arcade::ATexture> &texture,
                       const Arcade::Vector &pos,
                       const Arcade::Rect &rect)
    : ASprite(texture, pos, rect), _sfSprite()
{
    const auto &sfmlTexture = dynamic_cast<const SFMLTexture *>(texture.get());

    _sfSprite.setTexture(sfmlTexture->getSfTexure());

    setPosition(pos);
    setTextureRect(rect);
}

void SFMLSprite::setPosition(const Arcade::Vector &newPos)
{
    _pos = newPos;
    _sfSprite.setPosition(static_cast<float>(newPos.x), static_cast<float>(newPos.y));
}

void SFMLSprite::setTextureRect(const Arcade::Rect &newRect)
{
    _rect = newRect;
    _sfSprite.setTextureRect(sf::IntRect(static_cast<int>(_rect.pos.x), static_cast<int>(_rect.pos.y),
                                         static_cast<int>(_rect.size.x), static_cast<int>(_rect.size.y)));
}

const sf::Sprite &SFMLSprite::getSfSprite() const
{
    return _sfSprite;
}
