/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SFMLlib.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "IRenderer.hpp"

class SFMLlib final : public IRenderer {
public:
    SFMLlib() noexcept;

    void drawRectangle(const Rect &rect, const Color &color, bool fill) override;
    void drawCircle(const Vector &pos, double radius, const Color &color) override;
    void drawLine(const Vector &start, const Vector &end) override;
    void drawTexture(const std::string &imagePath, const Vector &pos) override;
    void drawText(const std::string &text, uint8_t fontSize, const Vector &pos) override;

    void display() override;
    void clear() override;

private:
    sf::RenderWindow window;
};

