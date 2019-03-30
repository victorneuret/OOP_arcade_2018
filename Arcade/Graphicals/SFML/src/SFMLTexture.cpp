/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SFMLTexture.cpp
*/

#include "SFMLTexture.hpp"

SFMLTexture::SFMLTexture(const void *buffer, const size_t &len)
    : ATexture(buffer, len), _sfTexure()
{
    if (!_sfTexure.loadFromMemory(buffer, len))
        throw std::runtime_error("Failed to load texture from memory");
}

const sf::Texture &SFMLTexture::getSfTexure() const
{
    return _sfTexure;
}
