/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SDL.cpp
*/

#include <iostream>

#include "IGraphicalLib.hpp"
#include "SDL.hpp"

SDL::SDL()
    : _renderer()
{}

uint8_t SDL::getGameKeyState() const noexcept
{
    const uint8_t *keyArray = SDL_GetKeyboardState(NULL);
    uint8_t key = 0;

    for (const auto &keyPair : _gameKeys)
        if (keyArray[keyPair.first])
            key += keyPair.second;
    return key;
}

uint8_t SDL::getCoreKeyState() const noexcept
{
    const uint8_t *keyArray = SDL_GetKeyboardState(NULL);
    uint8_t key = 0;

    for (const auto &keyPair : _coreKeys)
        if (keyArray[keyPair.first])
            key += keyPair.second;
    return key;
}

void SDL::sendGameKeyInput(GameKey) noexcept
{

}

void SDL::sendCoreKeyInput(CoreKey) noexcept
{

}

void SDL::pollEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event) != 0)
        if (event.type == SDL_QUIT)
            _closeRequested = true;
}

Arcade::IRenderer &SDL::getRenderer() noexcept
{
    return _renderer;
}

bool SDL::isCloseRequested() const noexcept
{
    return _closeRequested;
}
