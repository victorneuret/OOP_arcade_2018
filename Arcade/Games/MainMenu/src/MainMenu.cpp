/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** MainMenu.cpp
*/

#include <sstream>
#include <MainMenu.hpp>

#include "MainMenu.hpp"
#include "TestSprite.hpp"

void MainMenu::tick(Arcade::IGraphicLib *graphic, double deltaTime)
{
    _deltaTime = deltaTime;

    if (!graphic)
        return;

    if (_texture == nullptr) {
        _texture = graphic->createTexture(IMAGE_DATA, sizeof(IMAGE_DATA), Arcade::Color(42, 55, 88));
        _fullSprite = graphic->createSprite(_texture, Arcade::Rect(), Arcade::Rect(0.10, 0.10, 0.33, 0.33));
        _pacman = graphic->createSprite(_texture, Arcade::Rect(0, 0, 16, 16), Arcade::Rect(0, 0, 0.1, 0.1));
    }

    uint8_t key = graphic->getGameKeyState();

    for (const auto &c : _gameKeys)
        if (c.first & key)
            c.second();
}

void MainMenu::moveUp()
{
    if (_selection.second > 0)
        _selection.second -= 0.5 * _deltaTime;
}

void MainMenu::moveDown()
{
    if (_selection.second < 1)
        _selection.second += 0.5 * _deltaTime;
}

void MainMenu::moveLeft()
{
    if (_selection.first > 0)
        _selection.first -= 0.5 * _deltaTime;
}

void MainMenu::moveRight()
{
    if (_selection.first < 1)
        _selection.first += 0.5 * _deltaTime;
}

void MainMenu::primaryPressed()
{}

void MainMenu::render(Arcade::IGraphicLib *graphic)
{
    if (!graphic)
        return;
    graphic->getRenderer().clear();
    graphic->getRenderer().drawText("this is a test", 16, Arcade::Vector(_selection.first, _selection.second),
                                    Arcade::Color(0, 255, 0));
    graphic->getRenderer().drawSprite(*_fullSprite);
    graphic->getRenderer().drawSprite(*_pacman);
    graphic->getRenderer().drawRectangle(Arcade::Rect(0.33, 0.33, 0.66, 0.66), Arcade::Color(0, 42, 200), false);
    graphic->getRenderer().drawRectangle(Arcade::Rect(0.45, 0.45, 0.1, 0.1), Arcade::Color(0, 200, 42), true);
    graphic->getRenderer().display();
}

bool MainMenu::isCloseRequested() const noexcept
{
    return false;
}

void MainMenu::reloadResources(Arcade::IGraphicLib *)
{}
