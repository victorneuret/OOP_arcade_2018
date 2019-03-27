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

typedef struct snake_s {
    Arcade::Vector head;
    Arcade::Vector tail;
    std::vector<Arcade::Vector> body;
} snake_t;

class Nibbler final : public Arcade::IGame {
public:
    Nibbler() = default;
    ~Nibbler() override = default;

    void tick(Arcade::IGraphicLib *graphic, double deltaTime) override;
    void render(Arcade::IGraphicLib *graphic) override;
    bool isCloseRequested() const noexcept override;
    void reloadResources(Arcade::IGraphicLib *) override;

private:
    double _deltaTime = 0;
    double _time = 0;

    double _speed = 0.3;
    double _speedBoost = 0.0;
    Arcade::Vector _direction = {1.0, 0.0};
    size_t _ateFood = 0;

    char _maps[MAP_HIGH][MAP_WIDTH] = {
        "########################################",
        "#                                      #",
        "#                  #                   #",
        "#                                      #",
        "#                                  #   #",
        "#            #####   #                 #",
        "#                #   #                 #",
        "#                #   #                 #",
        "#                                      #",
        "#                #   #                 #",
        "#                #                     #",
        "#                #                     #",
        "#                #                     #",
        "#            #   #####                 #",
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
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
        "#                                      #",
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

    const snake_t _snakeDefault = {
        {19, 19},
        {15, 19},
        {
            {18, 19},
            {17, 19},
            {16, 19}
        }
    };
    snake_t _snake = _snakeDefault;

    void drawMap(Arcade::IGraphicLib *graphic);
    void drawSnake(Arcade::IGraphicLib *graphic);

    void move();
    void generateFood();
    void restart();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void speedBoost();

    const std::unordered_map<uint8_t, std::function<void ()>> _gameKeys = {
        {Arcade::IGraphicLib::UP, std::bind(&Nibbler::moveUp, this)},
        {Arcade::IGraphicLib::DOWN, std::bind(&Nibbler::moveDown, this)},
        {Arcade::IGraphicLib::LEFT, std::bind(&Nibbler::moveLeft, this)},
        {Arcade::IGraphicLib::RIGHT, std::bind(&Nibbler::moveRight, this)},
        {Arcade::IGraphicLib::PRIMARY, std::bind(&Nibbler::speedBoost, this)}
    };
};
