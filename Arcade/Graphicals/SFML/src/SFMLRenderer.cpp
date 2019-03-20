/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SFMLRenderer.cpp
*/

#include <iostream>

#include "IGraphicalLib.hpp"
#include "SFMLRenderer.hpp"

SFMLRenderer::SFMLRenderer() noexcept
    : _window(sf::VideoMode(800, 600), "SFML", sf::Style::Close), _sfFont()
{
    _sfFont.loadFromFile("res/arcade.ttf");
}

void SFMLRenderer::drawRectangle(const Arcade::Rect &rect, const Arcade::Color &color, bool fill)
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

void SFMLRenderer::drawTexture(const std::string &, const Arcade::Vector &)
{
}

void SFMLRenderer::drawText(const std::string &text, uint8_t fontSize, const Arcade::Vector &pos, const Arcade::Color &color)
{
    sf::Text sfText;

    sfText.setFillColor(sf::Color(color.getValue()));
    sfText.setFont(_sfFont);
    sfText.setString(text);
    sfText.setCharacterSize(fontSize);
    sfText.setPosition(static_cast<float>(pos.x), static_cast<float>(pos.y));

    _window.draw(sfText);
}

void SFMLRenderer::display()
{
    _window.display();
}

void SFMLRenderer::clear()
{
    _window.clear(sf::Color::Black);
}

sf::RenderWindow &SFMLRenderer::getWindow()
{
    return _window;
}
