/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Rect.cpp
*/

#include <Math/Rect.hpp>

#include "Math/Rect.hpp"

Arcade::Rect::Rect() noexcept
    : pos(Vector(0, 0)), size(Vector(0, 0))
{
}

Arcade::Rect::Rect(const Vector &pos, const Vector &size) noexcept
    : pos(pos), size(size)
{}

Arcade::Rect::Rect(double x, double y, double w, double h) noexcept
    : pos(Vector(x, y)), size(Vector(w, h))
{}

bool Arcade::Rect::operator==(const Arcade::Rect &rhs) const noexcept
{
    return pos == rhs.pos &&
           size == rhs.size;
}

bool Arcade::Rect::operator!=(const Arcade::Rect &rhs) const noexcept
{
    return !(rhs == *this);
}
