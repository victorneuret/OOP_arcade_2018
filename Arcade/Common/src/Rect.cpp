/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Rect.cpp
*/

#include "include/Math/Rect.hpp"

Rect::Rect(const Vector &pos, const Vector &size) noexcept
    : pos(pos), size(size)
{}

Rect::Rect(double x, double y, double w, double h) noexcept
    : pos(Vector(x, y)), size(Vector(w, h))
{}

Vector &Rect::getPosition() noexcept
{
    return pos;
}

Vector &Rect::getSize() noexcept
{
    return size;
}