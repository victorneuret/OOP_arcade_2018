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
    SFMLSprite(const std::shared_ptr<Arcade::ATexture> &texture,
               const Arcade::Vector &pos,
               const Arcade::Rect &rect = Arcade::Rect());
    ~SFMLSprite() override = default;

    void setPosition(const Arcade::Vector &newPos) override;
    void setTextureRect(const Arcade::Rect &newRect) override;
    const sf::Sprite &getSfSprite() const;
private:
    sf::Sprite _sfSprite;
};
