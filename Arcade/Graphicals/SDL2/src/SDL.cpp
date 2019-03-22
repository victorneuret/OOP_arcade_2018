/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SDL.cpp
*/

#include "IGraphicalLib.hpp"
#include "SDL.hpp"

SDL::SDL()
    : _renderer()
{}

uint8_t SDL::getGameKeyState() const noexcept
{
    SDL_Event event;
    uint8_t key = 0;

    while (SDL_PollEvent(&event) != 0)
        if (event.type == SDL_KEYDOWN)
            if (_gameKeys.find(event.key.keysym.sym) != _gameKeys.end())
                key += _gameKeys.at(event.key.keysym.sym);
    return key;
}

uint8_t SDL::getCoreKeyState() const noexcept
{
    SDL_Event event;
    uint8_t key = 0;

    while (SDL_PollEvent(&event) != 0)
        if (event.type == SDL_KEYDOWN)
            if (_coreKeys.find(event.key.keysym.sym) != _coreKeys.end())
                key += _coreKeys.at(event.key.keysym.sym);
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
