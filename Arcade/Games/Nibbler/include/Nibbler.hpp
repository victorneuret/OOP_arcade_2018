/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Nibbler.hpp
*/

#pragma once

#include <vector>
#include <unordered_map>
#include <functional>
#include <chrono>

#include "IGame.hpp"
#include "IGraphicalLib.hpp"

constexpr const uint8_t MAP_WIDTH = 41;
constexpr const uint8_t MAP_HIGH = 40;

class Nibbler final : public Arcade::IGame {
public:
    Nibbler() = default;
    ~Nibbler() override = default;

    struct Snake {
        Arcade::Vector head;
        Arcade::Vector tail;
        std::vector<Arcade::Vector> body;
    };

    void init(Arcade::IGraphicLib *graphic) override;
    void tick(Arcade::IGraphicLib *graphic, double deltaTime) override;
    void render(Arcade::IGraphicLib *graphic) override;
    bool isCloseRequested() const noexcept override;
    void reloadResources(Arcade::IGraphicLib *) override;
    bool isGameFinished() const noexcept override;
    size_t getScore() const noexcept override;

private:
    double _deltaTime = 0;
    double _time = 0;

    double _speed = 0.3;
    double _boost = 0.0;
    Arcade::Vector _direction = {1.0, 0.0};
    size_t _foodEaten = 0;
    size_t _score = 0;
    bool _isFinished = false;

    char _maps[MAP_HIGH][MAP_WIDTH] = {
        "########################################",
        "#                                      #",
        "#                  #                   #",
        "#                                      #",
        "#                                  #   #",
        "#                                      #",
        "#                #   #                 #",
        "#                #                     #",
        "#                                      #",
        "#                    #                 #",
        "#                #                     #",
        "#                                      #",
        "#                                      #",
        "#            #                         #",
        "#                                      #",
        "#                            @         #",
        "#                                      #",
        "#   #                                  #",
        "#                                      #",
        "#                                      #",
        "#                    ######            #",
        "#                         #            #",
        "#                         #            #",
        "#                         #            #",
        "#     ########                         #",
        "#         #                            #",
        "#         #                            #",
        "#         #                            #",
        "#         #                            #",
        "#         #                            #",
        "#                 #####                #",
        "#                     #                #",
        "#                                      #",
        "#                                      #",
        "#    #                                 #",
        "#    #                                 #",
        "#    #                                 #",
        "#                                      #",
        "#                          #           #",
        "########################################"
    };

    const Snake _snakeDefault = {
        {19, 19},
        {15, 19},
        {
            {18, 19},
            {17, 19},
            {16, 19}
        }
    };
    Snake _snake = _snakeDefault;

    void _drawMap(Arcade::IGraphicLib *graphic);
    void _drawSnake(Arcade::IGraphicLib *graphic);

    void _move();
    void _generateFood();
    void _restart();

    void _moveUp();
    void _moveDown();
    void _moveLeft();
    void _moveRight();
    void _speedBoost();

    const std::unordered_map<Arcade::IGraphicLib::GameKey, std::function<void ()>> _gameKeys = {
        {Arcade::IGraphicLib::UP, std::bind(&Nibbler::_moveUp, this)},
        {Arcade::IGraphicLib::DOWN, std::bind(&Nibbler::_moveDown, this)},
        {Arcade::IGraphicLib::LEFT, std::bind(&Nibbler::_moveLeft, this)},
        {Arcade::IGraphicLib::RIGHT, std::bind(&Nibbler::_moveRight, this)},
        {Arcade::IGraphicLib::PRIMARY, std::bind(&Nibbler::_speedBoost, this)}
    };
};
