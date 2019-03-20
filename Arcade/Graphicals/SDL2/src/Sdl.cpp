/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SDL.cpp
*/

#include "IGraphicalLib.hpp"
#include "Sdl.hpp"

extern "C"
Arcade::IGraphicLib *getInstance()
{
    return new Sdl;
}

Sdl::Sdl()
{}

uint8_t Sdl::getGameKeyState() const noexcept
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

uint8_t Sdl::getCoreKeyState() const noexcept
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

void Sdl::sendGameKeyInput(GameKey input) noexcept
{

}

void Sdl::sendCoreKeyInput(CoreKey input) noexcept
{

}

Arcade::IRenderer &Sdl::getRenderer() noexcept
{

}

bool Sdl::isCloseRequested() const noexcept
{

}
