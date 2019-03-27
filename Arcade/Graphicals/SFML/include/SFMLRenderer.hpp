/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SFMLRenderer.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "IRenderer.hpp"

constexpr float WIN_WIDTH = 800;
constexpr float WIN_HEIGHT = 800;

class SFMLRenderer final : public Arcade::IRenderer {
public:
    SFMLRenderer();
    ~SFMLRenderer() override = default;

    void drawRectangle(const Arcade::Rect &rect, const Arcade::Color &color, bool fill) override;
    void drawSprite(const Arcade::ASprite &sprite) override;
    void drawText(const std::string &text, uint8_t fontSize, const Arcade::Vector &pos, const Arcade::Color &color) override;

    void display() override;
    void clear() override;

    sf::RenderWindow &getWindow();
private:
    sf::RenderWindow _window;
    sf::Font _sfFont;
};
