/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Rect.cpp
*/

#include "Math/Rect.hpp"

Arcade::Rect::Rect(const Vector &pos, const Vector &size) noexcept
    : pos(pos), size(size)
{}

Arcade::Rect::Rect(double x, double y, double w, double h) noexcept
    : pos(Vector(x, y)), size(Vector(w, h))
{}