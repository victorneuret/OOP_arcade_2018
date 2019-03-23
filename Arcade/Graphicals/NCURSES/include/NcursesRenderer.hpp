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

class NcursesRenderer final : public Arcade::IRenderer {
public:
    NcursesRenderer();
    ~NcursesRenderer() override;

    void drawRectangle(const Arcade::Rect &rect, const Arcade::Color &color, bool fill) override;
    void drawSprite(const Arcade::ASprite &sprite) override;
    void drawText(const std::string &text, uint8_t fontSize, const Arcade::Vector &pos, const Arcade::Color &color) override;

    void display() override;
    void clear() override;

private:
    void _initColor(const Arcade::Color &color, bool fill = false) const noexcept;
};
