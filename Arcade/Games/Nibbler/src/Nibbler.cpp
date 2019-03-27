/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Nibbler.cpp
*/

#include <sstream>
#include <iostream>
#include <algorithm>
#include <unistd.h>

#include "Nibbler.hpp"

void Nibbler::tick(Arcade::IGraphicLib *graphic)
{
    if (!graphic)
        return;

    uint8_t key = graphic->getGameKeyState();

    for (const auto &c : _gameKeys) {
        if (c.first & key)
            c.second();
    }
    usleep(20000);
}

void Nibbler::render(Arcade::IGraphicLib *graphic)
{
    if (!graphic)
        return;
    graphic->getRenderer().clear();
    drawMap(graphic);
    drawSnake(graphic);
    graphic->getRenderer().display();
}

bool Nibbler::isCloseRequested() const noexcept
{
    return false;
}

void Nibbler::reloadResources(Arcade::IGraphicLib *)
{}

void Nibbler::drawMap(Arcade::IGraphicLib *graphic)
{
    for (size_t i = 0; i < MAP_HIGH; i++) {
        for (size_t j = 0; j < MAP_WIDTH; j++) {
            if (_maps[i][j] == '#') {
                graphic->getRenderer().drawRectangle(
                    Arcade::Rect{
                        static_cast<double>(j) / (MAP_WIDTH - 1),
                        static_cast<double>(i) / MAP_HIGH,
                        1.0 / (MAP_WIDTH - 1),
                        1.0 / MAP_HIGH
                    },
                    Arcade::Color(0xf4, 0xa7, 0xb7)
                );
            } else if (_maps[i][j] == '@') {
                graphic->getRenderer().drawRectangle(
                    Arcade::Rect{
                        static_cast<double>(j) / (MAP_WIDTH - 1),
                        static_cast<double>(i) / MAP_HIGH,
                        1.0 / (MAP_WIDTH - 1),
                        1.0 / MAP_HIGH
                    },
                    Arcade::Color(0xa7, 0x42, 0x42)
                );
            }
        }
    }
}

void Nibbler::drawSnake(Arcade::IGraphicLib *graphic)
{
    graphic->getRenderer().drawRectangle(
        Arcade::Rect{
            _snake.head.x / (MAP_WIDTH - 1),
            _snake.head.y / MAP_HIGH,
            1.0 /  (MAP_WIDTH - 1),
            1.0 / MAP_HIGH
        },
        {0x00, 0xd7, 0x00}
    );
    graphic->getRenderer().drawRectangle(
        Arcade::Rect{
            _snake.tail.x /  (MAP_WIDTH - 1),
            _snake.tail.y / MAP_HIGH,
            1.0 /  (MAP_WIDTH - 1),
            1.0 / MAP_HIGH
        },
        {0x00, 0xa0, 0x00}
    );

    for (const auto &rect : _snake.body) {
        graphic->getRenderer().drawRectangle(
            Arcade::Rect{
                rect.x /  (MAP_WIDTH - 1),
                rect.y / MAP_HIGH,
                1.0 /  (MAP_WIDTH - 1),
                1.0 / MAP_HIGH
            },
            {0xff, 0xff, 0xb7}
        );
    }
}

void Nibbler::move(const Arcade::Vector &head)
{
    if (_maps[static_cast<int>(head.y)][static_cast<int>(head.x)] == '#'
        || Arcade::Vector(head.x, head.y) == _snake.body.front())
        return;

    auto first = _snake.body.begin();

    _snake.body.insert(first, _snake.head);
    _snake.head.x = head.x;
    _snake.head.y = head.y;
    if (_maps[static_cast<int>(_snake.head.y)][static_cast<int>(_snake.head.x)] != '@') {
        _snake.tail = _snake.body.back();
        _snake.body.pop_back();
    } else {
        _maps[static_cast<int>(_snake.head.y)][static_cast<int>(_snake.head.x)] = ' ';
    }
}

void Nibbler::moveUp()
{
    move(Arcade::Vector(_snake.head.x, _snake.head.y - 1));
}

void Nibbler::moveDown()
{
    move(Arcade::Vector(_snake.head.x, _snake.head.y + 1));
}

void Nibbler::moveLeft()
{
    move(Arcade::Vector(_snake.head.x - 1, _snake.head.y));
}

void Nibbler::moveRight()
{
    move(Arcade::Vector(_snake.head.x + 1, _snake.head.y));
}