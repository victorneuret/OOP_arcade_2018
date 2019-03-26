/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SFMLRenderer.cpp
*/

#include <iostream>

#include "IGraphicalLib.hpp"
#include "SFMLRenderer.hpp"
#include "SFMLSprite.hpp"

SFMLRenderer::SFMLRenderer()
    : _window(sf::VideoMode((int) WIN_WIDTH, (int) WIN_HEIGHT), "SFML", sf::Style::Close), _sfFont()
{
    if (!_sfFont.loadFromFile("res/arcade.ttf"))
        throw std::runtime_error("Failed to load default font");

    _window.setFramerateLimit(120);
    _window.setPosition(sf::Vector2i(100, 100));
}

void SFMLRenderer::drawRectangle(const Arcade::Rect &rect, const Arcade::Color &color, bool fill)
{
    sf::RectangleShape sfRect;

    sfRect.setPosition(static_cast<float>(rect.pos.x * WIN_WIDTH),
                       static_cast<float>(rect.pos.y * WIN_HEIGHT));
    sfRect.setSize(sf::Vector2f(static_cast<float>(rect.size.x * WIN_WIDTH),
                                static_cast<float>(rect.size.y * WIN_HEIGHT)));

    if (fill) {
        sfRect.setFillColor(sf::Color(color.getValue()));
    } else {
        sfRect.setOutlineColor(sf::Color(color.getValue()));
        sfRect.setOutlineThickness(2);
        sfRect.setFillColor(sf::Color::Transparent);
    }

    _window.draw(sfRect);
}

void SFMLRenderer::drawSprite(const Arcade::ASprite &sprite)
{
    const auto &sfmlSprite = dynamic_cast<const SFMLSprite *>(&sprite);

    _window.draw(sfmlSprite->getSfSprite());
}

void SFMLRenderer::drawText(const std::string &text, uint8_t fontSize, const Arcade::Vector &pos, const Arcade::Color &color)
{
    sf::Text sfText;

    sfText.setFillColor(sf::Color(color.getValue()));
    sfText.setFont(_sfFont);
    sfText.setString(text);
    sfText.setCharacterSize(fontSize);
    sfText.setPosition(static_cast<float>(pos.x * WIN_WIDTH), static_cast<float>(pos.y * WIN_HEIGHT));

    _window.draw(sfText);
}

void SFMLRenderer::display()
{
    _window.display();
}

void SFMLRenderer::clear()
{
    _window.clear(sf::Color(0, 0, 0));
}

sf::RenderWindow &SFMLRenderer::getWindow()
{
    return _window;
}
