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

    Vector getPosition() const noexcept;
    void setPosition(const Vector &newPos) noexcept;
    void setPosition(const double x, const double y) noexcept;
    Vector getSize() const noexcept;
    void setSize(const Vector &newSize) noexcept;
    void setSize(const double w, const double h) noexcept;
};