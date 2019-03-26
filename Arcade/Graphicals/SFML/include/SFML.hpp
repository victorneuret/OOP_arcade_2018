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

    Arcade::ATexture *createTexture(const void *buffer, const size_t &len, const Arcade::Color &fallbackColor) override;
    Arcade::ASprite *createSprite(const Arcade::ATexture *texture, const Arcade::Rect &spriteSheetRect,
                                  const Arcade::Rect &posAndSize) override;

    Arcade::IRenderer &getRenderer() noexcept override;
    bool isCloseRequested() const noexcept override;
private:
    SFMLRenderer renderer;
    bool _closeRequested = false;

    const std::unordered_map<sf::Keyboard::Key, GameKey> _gameKeys = {
        {sf::Keyboard::Z, GameKey::UP},
        {sf::Keyboard::S, GameKey::DOWN},
        {sf::Keyboard::Q, GameKey::LEFT},
        {sf::Keyboard::D, GameKey::RIGHT},
        {sf::Keyboard::O, GameKey::PRIMARY},
        {sf::Keyboard::P, GameKey::SECONDARY},
        {sf::Keyboard::K, GameKey::START},
        {sf::Keyboard::L, GameKey::SELECT}
    };

    const std::unordered_map<sf::Keyboard::Key, CoreKey> _coreKeys = {
        {sf::Keyboard::B, CoreKey::PREV_GRAPHICAL_LIB},
        {sf::Keyboard::N, CoreKey::NEXT_GRAPHICAL_LIB},
        {sf::Keyboard::C, CoreKey::PREV_GAME_LIB},
        {sf::Keyboard::V, CoreKey::NEXT_GAME_LIB},
        {sf::Keyboard::R, CoreKey::RESTART_GAME},
        {sf::Keyboard::A, CoreKey::BACK_TO_MENU},
        {sf::Keyboard::E, CoreKey::EXIT}
    };
};

