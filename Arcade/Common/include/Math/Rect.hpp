/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Rect.hpp
*/

#pragma once

#include "Vector.hpp"

struct Rect {
    Vector pos;
    Vector size;

    Rect(const Vector &pos, const Vector &size) noexcept;
    Rect(double x, double y, double w, double h) noexcept;
    ~Rect() = default;

    Vector &getPosition() const noexcept;
    Vector &getSize() const noexcept;
};