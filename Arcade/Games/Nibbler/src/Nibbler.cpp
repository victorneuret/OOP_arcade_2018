/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Nibbler.cpp
*/

#include <sstream>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>

#include "Nibbler.hpp"

void Nibbler::init(Arcade::IGraphicLib *)
{
}

void Nibbler::tick(Arcade::IGraphicLib *graphic, double deltaTime)
{
    static size_t nbSpace = 0;
    _deltaTime = deltaTime;

    if (!graphic)
        return;
    if (nbSpace == 0) {
        srand(time(nullptr));
        for (size_t i = 0; i < MAP_HIGH; i++)
            for (size_t j = 0; j < MAP_WIDTH; j++)
                if (_maps[i][j] == ' ')
                    nbSpace++;
    }

    auto key = graphic->getGameKeyState();
    _boost = 0;
    for (const auto &c : _gameKeys) {
        if (c.first & key)
            c.second();
    }

    _time += _deltaTime;
    if (_time >= (_speed - _boost)) {
        _move();
        _time -= _speed - _boost;
    }

    if ((_snake.body.size() + 2) == nbSpace)
        _restart();
}

void Nibbler::render(Arcade::IGraphicLib *graphic)
{
    if (!graphic)
        return;
    graphic->getRenderer().clear();
    _drawMap(graphic);
    _drawSnake(graphic);
    graphic->getRenderer().drawText(std::to_string(_foodEaten), 22, Arcade::Vector(0.5, 0), Arcade::Color(0, 0, 0));
    graphic->getRenderer().display();
}

bool Nibbler::isCloseRequested() const noexcept
{
    return false;
}

void Nibbler::reloadResources(Arcade::IGraphicLib *)
{}

void Nibbler::_drawMap(Arcade::IGraphicLib *graphic)
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

void Nibbler::_drawSnake(Arcade::IGraphicLib *graphic)
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

void Nibbler::_move()
{
    Arcade::Vector head = _snake.head + _direction;
    if (_maps[static_cast<int>(head.y)][static_cast<int>(head.x)] == '#'
        || std::find(_snake.body.begin(), _snake.body.end(), head) != _snake.body.end()
        || head == _snake.tail)
        return _restart();

    auto first = _snake.body.begin();

    _snake.body.insert(first, _snake.head);
    _snake.head.x = head.x;
    _snake.head.y = head.y;
    if (_maps[static_cast<int>(_snake.head.y)][static_cast<int>(_snake.head.x)] != '@') {
        _snake.tail = _snake.body.back();
        _snake.body.pop_back();
    } else {
        _maps[static_cast<int>(_snake.head.y)][static_cast<int>(_snake.head.x)] = ' ';
        _foodEaten++;
        if (_foodEaten > 1 && _speed > 0.06 && _foodEaten % 2 == 0)
            _speed -= 0.01;
        _generateFood();
    }
}

void Nibbler::_moveUp()
{
    if (_snake.body.front() != (_snake.head + Arcade::Vector(0, -1)))
        _direction = {0, -1};
}

void Nibbler::_moveDown()
{
    if (_snake.body.front() != (_snake.head + Arcade::Vector(0, 1)))
        _direction = {0, 1};
}

void Nibbler::_moveLeft()
{
    if (_snake.body.front() != (_snake.head + Arcade::Vector(-1, 0)))
        _direction = {-1, 0};
}

void Nibbler::_moveRight()
{
    if (_snake.body.front() != (_snake.head + Arcade::Vector(1, 0)))
        _direction = {1, 0};
}

void Nibbler::_speedBoost()
{
   _boost = _speed / 2;
}

void Nibbler::_generateFood()
{
    Arcade::Vector food(0.0, 0.0);

    do {
        food = {
            static_cast<double>((rand() % (MAP_WIDTH - 2)) + 1),
            static_cast<double>((rand() % (MAP_HIGH - 1)) + 1)
        };
    } while (_maps[static_cast<int>(food.y)][static_cast<int>(food.x)] != ' ');
    _maps[static_cast<int>(food.y)][static_cast<int>(food.x)] = '@';
}

void Nibbler::_restart()
{
    _snake.head = _snakeDefault.head;
    _snake.body.clear();
    _snake.body = _snakeDefault.body;
    _snake.tail = _snakeDefault.tail;
    _direction = {1, 0};
    _speed = 0.3;
    _foodEaten = 0;
}
