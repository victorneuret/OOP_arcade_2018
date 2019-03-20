/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SFMLlib.cpp
*/

#include "SFMLlib.hpp"

SFMLlib::SFMLlib() noexcept
    : _window(sf::VideoMode(800, 600), "SFML", sf::Style::Close)
{
}

void SFMLlib::drawRectangle(const Arcade::Rect &rect, const Arcade::Color &color, bool fill)
{
    sf::RectangleShape sfRect;

    sfRect.setPosition(static_cast<float>(rect.pos.x), static_cast<float>(rect.pos.y));
    sfRect.setSize(sf::Vector2f(static_cast<float>(rect.size.x), static_cast<float>(rect.size.y)));

    if (fill) {
        sfRect.setFillColor(sf::Color(color.getValue()));
    } else {
        sfRect.setOutlineColor(sf::Color(color.getValue()));
        sfRect.setOutlineThickness(2);
        sfRect.setFillColor(sf::Color::Transparent);
    }

    _window.draw(sfRect);
}

void SFMLlib::drawTexture(const std::string &imagePath, const Arcade::Vector &pos)
{
}

void SFMLlib::drawText(const std::string &text, uint8_t fontSize, const Arcade::Vector &pos)
{
}

void SFMLlib::display()
{
    _window.display();
}

void SFMLlib::clear()
{
    _window.clear(sf::Color::Black);
}
