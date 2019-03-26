/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** NcursesRenderer.hpp
*/

#pragma once

#include <string>
#include <ncurses.h>
#include <vector>

#include "Math/Rect.hpp"
#include "Graphical/Color.hpp"
#include "IRenderer.hpp"

class NcursesRenderer final : public Arcade::IRenderer {
public:
    NcursesRenderer();
    NcursesRenderer(const NcursesRenderer &) = default;
    ~NcursesRenderer() override;

    void drawRectangle(const Arcade::Rect &rect, const Arcade::Color &color, bool fill) override;
    void drawSprite(const Arcade::ASprite &sprite) override;
    void drawText(const std::string &text, uint8_t fontSize, const Arcade::Vector &pos, const Arcade::Color &color) override;

    void display() override;
    void clear() override;

    NcursesRenderer &operator=(const NcursesRenderer &) = default;

private:
    void _initColor(const Arcade::Color &color, bool fill = false) noexcept;

    WINDOW *_win = nullptr;
    uint16_t _colorIndex = 0;
    int32_t _size = 0;
};
