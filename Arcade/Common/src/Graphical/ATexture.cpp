/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** ATexture.cpp
*/

#include <Graphical/ATexture.hpp>

#include "Graphical/ATexture.hpp"

Arcade::ATexture::ATexture(const void *buffer, const size_t &len, const Arcade::Color &fallbackColor)
    : _buffer(buffer), _len(len), _fallbackColor(fallbackColor)
{
}

const void *Arcade::ATexture::getBuffer() const noexcept
{
    return _buffer;
}

const size_t &Arcade::ATexture::getBufferLength() const noexcept
{
    return _len;
}

const Arcade::Color &Arcade::ATexture::getFallbackColor() const noexcept
{
    return _fallbackColor;
}
