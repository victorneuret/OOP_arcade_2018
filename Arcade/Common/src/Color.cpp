/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Rect.cpp
*/

#include <cstdint>

#include "Graphical/Color.hpp"


Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) noexcept
    : r(r), g(g), b(b), a(a)
{}

uint32_t Color::getValue() const noexcept
{
    return (r << 24) | (g << 16) | (b << 8) | (a);
}