/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SFML.hpp
*/

#pragma once

#include <map>

#include "IGraphicalLib.hpp"
#include "SFMLRenderer.hpp"

class SFML : public Arcade::IGraphicLib {
public:
    SFML();
    ~SFML() override = default;

    uint8_t getGameKeyState() const noexcept override;
    uint8_t getCoreKeyState() const noexcept override;
    void sendGameKeyInput(GameKey input) noexcept override;
    void sendCoreKeyInput(CoreKey input) noexcept override;
    void pollEvents() override;

    Arcade::IRenderer &getRenderer() noexcept override;
    bool isCloseRequested() const noexcept override;
private:
    SFMLRenderer renderer;
    bool _closeRequested = false;

    const std::map<sf::Keyboard::Key, GameKey> _gameKeysAssociations = {
        { sf::Keyboard::Up,    GameKey::UP },
        { sf::Keyboard::Down,  GameKey::DOWN },
        { sf::Keyboard::Left,  GameKey::LEFT },
        { sf::Keyboard::Right, GameKey::RIGHT }
    };
};
