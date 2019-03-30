/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SFML.hpp
*/

#pragma once

#include <unordered_map>

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

    Arcade::ATexture *createTexture(const void *buffer, const size_t &len) override;
    Arcade::ASprite *createSprite(const Arcade::ATexture *texture, const Arcade::Rect &spriteSheetRect,
                                  const Arcade::Rect &posAndSize) override;

    Arcade::IRenderer &getRenderer() noexcept override;
    bool isCloseRequested() const noexcept override;
private:
    SFMLRenderer renderer;
    bool _closeRequested = false;

    const std::unordered_map<sf::Keyboard::Key, GameKey> _gameKeys = {
        {sf::Keyboard::Up,    GameKey::UP},
        {sf::Keyboard::Down,  GameKey::DOWN},
        {sf::Keyboard::Left,  GameKey::LEFT},
        {sf::Keyboard::Right, GameKey::RIGHT},
        {sf::Keyboard::X,     GameKey::PRIMARY},
        {sf::Keyboard::C,     GameKey::SECONDARY},
        {sf::Keyboard::B,     GameKey::START},
        {sf::Keyboard::N,     GameKey::SELECT}
    };

    const std::unordered_map<sf::Keyboard::Key, CoreKey> _coreKeys = {
        {sf::Keyboard::F1,     CoreKey::PREV_GRAPHICAL_LIB},
        {sf::Keyboard::F2,     CoreKey::NEXT_GRAPHICAL_LIB},
        {sf::Keyboard::F3,     CoreKey::PREV_GAME_LIB},
        {sf::Keyboard::F4,     CoreKey::NEXT_GAME_LIB},
        {sf::Keyboard::F5,     CoreKey::RESTART_GAME},
        {sf::Keyboard::Escape, CoreKey::BACK_TO_MENU},
        {sf::Keyboard::F9,     CoreKey::EXIT}
    };
};

