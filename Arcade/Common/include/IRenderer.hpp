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

namespace Arcade {
    class IRenderer {
    public:
        virtual ~IRenderer() = 0;

        virtual void drawRectangle(const Rect &rect, const Color &color, bool fill = true) = 0;
        virtual void drawLine(const Vector &start, const Vector &end, const Color &color) = 0;
        virtual void drawTexture(const std::string &imagePath, const Vector &pos) = 0;
        virtual void drawText(const std::string &text, uint8_t fontSize, const Vector &pos, const Color &color) = 0;
        virtual void display() = 0;
        virtual void clear() = 0;
    };
}
