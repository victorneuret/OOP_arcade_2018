/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SFMLSprite.cpp
*/

#include "SFML.hpp"
#include "SFMLSprite.hpp"
#include "SFMLTexture.hpp"

SFMLSprite::SFMLSprite(const Arcade::ATexture *texture,
                       const Arcade::Rect &spriteSheetRect,
                       const Arcade::Rect &posAndSize)
    : ASprite(texture, spriteSheetRect, posAndSize), _sfSprite()
{
    const auto &sfmlTexture = dynamic_cast<const SFMLTexture *>(texture);

    _sfSprite.setTexture(sfmlTexture->getSfTexure());

    setTextureRect(spriteSheetRect);
    setPosAndSize(posAndSize);
}

void SFMLSprite::setPosAndSize(const Arcade::Rect &posAndSize)
{
    const auto size = _sfSprite.getTexture()->getSize();

    _posAndSize = posAndSize;
    _sfSprite.setPosition(static_cast<float>(_posAndSize.pos.x * WIN_WIDTH),
                          static_cast<float>(_posAndSize.pos.y * WIN_HEIGHT));

    if (_spriteSheetRect.size == Arcade::Vector(0, 0))
        _sfSprite.setScale(static_cast<float>(_posAndSize.size.x * WIN_WIDTH / size.x),
                           static_cast<float>(_posAndSize.size.y * WIN_HEIGHT / size.y));
    else
        _sfSprite.setScale(static_cast<float>(_posAndSize.size.x * WIN_WIDTH / _spriteSheetRect.size.x),
                           static_cast<float>(_posAndSize.size.y * WIN_HEIGHT / _spriteSheetRect.size.y));
}

void SFMLSprite::setTextureRect(const Arcade::Rect &newRect)
{
    _spriteSheetRect = newRect;

    if (newRect != Arcade::Rect())
        _sfSprite.setTextureRect(sf::IntRect(static_cast<int>(_spriteSheetRect.pos.x),
                                             static_cast<int>(_spriteSheetRect.pos.y),
                                             static_cast<int>(_spriteSheetRect.size.x),
                                             static_cast<int>(_spriteSheetRect.size.y)));
}

const sf::Sprite &SFMLSprite::getSfSprite() const
{
    return _sfSprite;
}
