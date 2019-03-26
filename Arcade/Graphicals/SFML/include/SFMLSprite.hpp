/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SFMLSprite.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "Graphical/ASprite.hpp"

class SFMLSprite : public Arcade::ASprite {
public:
    SFMLSprite(const Arcade::ATexture *texture, const Arcade::Rect &spriteSheetRect, const Arcade::Rect &posAndSize);
    ~SFMLSprite() override = default;

    SFMLSprite(const ASprite &sprite) = delete;
    ASprite &operator=(const ASprite &sprite) override = delete;

    void setPosAndSize(const Arcade::Rect &posAndSize) override;
    void setTextureRect(const Arcade::Rect &newRect) override;

    const sf::Sprite &getSfSprite() const;
private:
    sf::Sprite _sfSprite;
};
