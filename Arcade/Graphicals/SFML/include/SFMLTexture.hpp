/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SFMLTexture.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "Graphical/ATexture.hpp"

class SFMLTexture : public Arcade::ATexture {
public:
    SFMLTexture(const void *buffer, const size_t &len);
    ~SFMLTexture() override = default;

    const sf::Texture &getSfTexure() const;
private:
    sf::Texture _sfTexure;
};

