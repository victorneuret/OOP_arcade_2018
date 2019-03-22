/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SDL.cpp
*/

#include "IGraphicalLib.hpp"
#include "SDL.hpp"

extern "C"
Arcade::IGraphicLib *getInstance()
{
    return new SDL;
}

SDL::SDL()
    : _renderer()
{}

uint8_t SDL::getGameKeyState() const noexcept
{
    SDL_Event event;
    uint8_t key = 0;

    while (SDL_PollEvent(&event) != 0)
        if (event.type == SDL_KEYDOWN)
            key = event.key.keysym.sym;
    if (_gameKeys.find(key) != _gameKeys.end())
        return _gameKeys.at(key);
    return 0;
}

uint8_t SDL::getCoreKeyState() const noexcept
{
    SDL_Event event;
    uint8_t key = 0;

    while (SDL_PollEvent(&event) != 0)
        if (event.type == SDL_KEYDOWN)
            key = event.key.keysym.sym;
    if (_coreKeys.find(key) != _coreKeys.end())
        return _coreKeys.at(key);
    return 0;
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
