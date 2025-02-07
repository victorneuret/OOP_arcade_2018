/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Color.hpp
*/

#pragma once

#include <cstdint>

namespace Arcade {
    struct Color final {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;

        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) noexcept;
        ~Color() = default;

        Color &operator=(const Color& rhs) noexcept = default;

        uint32_t getValue() const noexcept;
    };
}