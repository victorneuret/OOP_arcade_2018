/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** NcursesRenderer.hpp
*/

#pragma once

#include <string>
#include <ncurses.h>

#include "Math/Rect.hpp"
#include "Graphical/Color.hpp"
#include "IRenderer.hpp"

class NcursesRenderer : public IRenderer {
public:
    NcursesRenderer();
    ~NcursesRenderer() override;

    void drawRectangle(const Rect &rect, const Color &color, bool fill) override;
    void drawLine(const Vector &start, const Vector &end, const Color &color) override;
    void drawTexture(const std::string &imagePath, const Vector &pos) override;
    void drawText(const std::string &text, uint8_t fontSize, const Vector &pos, const Color &color) override;

    void display() override;
    void clear() override;

private:
    void _init_color(const Color &color, bool fill = false) const noexcept;
};

