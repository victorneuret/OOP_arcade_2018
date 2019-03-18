/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Rect.cpp
*/

#include "Math/Rect.hpp"

Rect::Rect(const Vector &pos, const Vector &size) noexcept
    : pos(pos), size(size)
{}

Rect::Rect(double x, double y, double w, double h) noexcept
    : pos(Vector(x, y)), size(Vector(w, h))
{}

Vector Rect::getPosition() const noexcept
{
    return pos;
}

void Rect::setPosition(const Vector &newPos) noexcept
{
    pos = newPos;
}

void Rect::setPosition(const double x, const double y) noexcept
{
    pos.x = x;
    pos.y = y;
}

Vector Rect::getSize() const noexcept
{
    return size;
}

void Rect::setSize(const Vector &newSize) noexcept
{
    size = newSize;
}

void Rect::setSize(const double w, const double h) noexcept
{
    size.x = w;
    size.y = h;
}