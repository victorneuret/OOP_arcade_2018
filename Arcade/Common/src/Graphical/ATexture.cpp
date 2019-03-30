/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** ATexture.cpp
*/

#include <Graphical/ATexture.hpp>

#include "Graphical/ATexture.hpp"

Arcade::ATexture::ATexture(const void *buffer, const size_t &len)
    : _buffer(buffer), _len(len)
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
