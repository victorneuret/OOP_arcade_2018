/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SFMLlib.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "IRenderer.hpp"

class SFMLlib final : public Arcade::IRenderer {
public:
    SFMLlib() noexcept;

    void drawRectangle(const Arcade::Rect &rect, const Arcade::Color &color, bool fill) override;
    void drawTexture(const std::string &imagePath, const Arcade::Vector &pos) override;
    void drawText(const std::string &text, uint8_t fontSize, const Arcade::Vector &pos, const Arcade::Color &color) override;

    void display() override;
    void clear() override;

private:
    sf::RenderWindow _window;
};

