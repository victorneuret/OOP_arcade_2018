/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Rect.hpp
*/

#pragma once

#include "Vector.hpp"

namespace Arcade {
    struct Rect final {
        Vector pos;
        Vector size;

        Rect() noexcept;
        Rect(const Vector &pos, const Vector &size) noexcept;
        Rect(double x, double y, double w, double h) noexcept;
        ~Rect() = default;

        bool operator==(const Rect &rhs) const;
        bool operator!=(const Rect &rhs) const;
    };
}