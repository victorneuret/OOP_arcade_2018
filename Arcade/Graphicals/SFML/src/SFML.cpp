/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SFML.cpp
*/

#include <SFML/Graphics.hpp>

#include "SFML.hpp"

SFML::SFML()
    : renderer()
{}

uint8_t SFML::getGameKeyState() const noexcept
{
    uint8_t state = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        state += GameKey::UP;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        state += GameKey::DOWN;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        state += GameKey::LEFT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        state += GameKey::RIGHT;

    return state;
}

uint8_t SFML::getCoreKeyState() const noexcept
{
    return 0;
}

void SFML::sendGameKeyInput(Arcade::IGraphicLib::GameKey) noexcept
{
}

void SFML::sendCoreKeyInput(Arcade::IGraphicLib::CoreKey) noexcept
{
}

void SFML::pollEvents()
{
    sf::Event event {};

    while (renderer.getWindow().pollEvent(event))
        if (event.type == sf::Event::Closed)
            _closeRequested = true;
}

Arcade::IRenderer &SFML::getRenderer() noexcept
{
    return renderer;
}

bool SFML::isCloseRequested() const noexcept
{
    return _closeRequested;
}
