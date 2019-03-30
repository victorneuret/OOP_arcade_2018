/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SFML.cpp
*/

#include <SFML/Graphics.hpp>

#include "SFML.hpp"
#include "SFMLSprite.hpp"
#include "SFMLTexture.hpp"

SFML::SFML()
    : renderer()
{}

uint8_t SFML::getGameKeyState() const noexcept
{
    uint8_t state = 0;

    for (const auto &keyPair : _gameKeys)
        if (sf::Keyboard::isKeyPressed(keyPair.first))
            state += keyPair.second;

    return state;
}

uint8_t SFML::getCoreKeyState() const noexcept
{
    uint8_t state = 0;

    for (const auto &keyPair : _coreKeys)
        if (sf::Keyboard::isKeyPressed(keyPair.first))
            state += keyPair.second;

    return state;
}

void SFML::sendGameKeyInput(Arcade::IGraphicLib::GameKey) noexcept
{}

void SFML::sendCoreKeyInput(Arcade::IGraphicLib::CoreKey) noexcept
{}

void SFML::pollEvents()
{
    sf::Event event {};

    while (renderer.getWindow().pollEvent(event))
        if (event.type == sf::Event::Closed)
            _closeRequested = true;
}

Arcade::ATexture *SFML::createTexture(const void *buffer, const size_t &len)
{
    return new SFMLTexture(buffer, len);
}

Arcade::ASprite *SFML::createSprite(const Arcade::ATexture *texture, const Arcade::Rect &spriteSheetRect, const Arcade::Rect &posAndSize)
{
    return new SFMLSprite(texture, spriteSheetRect, posAndSize);
}

Arcade::IRenderer &SFML::getRenderer() noexcept
{
    return renderer;
}

bool SFML::isCloseRequested() const noexcept
{
    return _closeRequested;
}
