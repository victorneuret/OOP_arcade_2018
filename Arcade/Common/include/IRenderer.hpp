/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** IRenderer.hpp
*/

#pragma once

#include <string>

#include "Math/Rect.hpp"
#include "Math/Vector.hpp"
#include "Graphical/Color.hpp"
#include "Graphical/ASprite.hpp"

namespace Arcade {
    class IRenderer {
    public:
        virtual ~IRenderer() = default;

        virtual void drawRectangle(const Rect &rect, const Color &color, bool fill = true) = 0;
        virtual void drawSprite(const ASprite *sprite) = 0;
        virtual void drawText(const std::string &text, uint8_t fontSize, const Vector &pos, const Color &color) = 0;

        virtual void display() = 0;
        virtual void clear() = 0;
    };
}
