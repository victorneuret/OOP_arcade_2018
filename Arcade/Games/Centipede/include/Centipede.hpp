/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Centipede.hpp
*/

#pragma once

#include <vector>
#include <functional>
#include <unordered_map>

#include "IGame.hpp"

constexpr double PLAYER_WIDTH = 0.04;
constexpr double PLAYER_HEIGHT = 0.04;
constexpr double PLAYER_SPEED = 0.6;

constexpr double BOARD_WIDTH = 1;
constexpr double BOARD_HEIGHT = 0.76;

constexpr double CELL_SIZE = 0.033;

constexpr double CELL_COUNT_X = BOARD_WIDTH / CELL_SIZE;
constexpr double CELL_COUNT_Y = BOARD_HEIGHT / CELL_SIZE;

constexpr double OBSTACLE_PERCENTAGE = 5;

class Centipede final : public Arcade::IGame {
public:
    Centipede();
    ~Centipede() override;

    void init(Arcade::IGraphicLib *graphic) override;
    void tick(Arcade::IGraphicLib *graphic, double deltaTime) override;
    void render(Arcade::IGraphicLib *graphic) override;
    bool isCloseRequested() const noexcept override;
    void reloadResources(Arcade::IGraphicLib *lib) override;

private:
    struct Cell {
        Arcade::Vector pos{0, 0};
        bool hasObstacle = false;
        uint8_t obstacleHealth = 5;
    };

    void _moveUp();
    void _moveDown();
    void _moveLeft();
    void _moveRight();

    const std::unordered_map<Arcade::IGraphicLib::GameKey, std::function<void()>> _gameKeys = {
        {Arcade::IGraphicLib::UP,    std::bind(&Centipede::_moveUp, this)},
        {Arcade::IGraphicLib::DOWN,  std::bind(&Centipede::_moveDown, this)},
        {Arcade::IGraphicLib::LEFT,  std::bind(&Centipede::_moveLeft, this)},
        {Arcade::IGraphicLib::RIGHT, std::bind(&Centipede::_moveRight, this)}
    };

    bool _closeRequested = false;
    double _deltaTime = 0;

    Arcade::Vector _playerPos{0.5, 0.9};
    std::vector<Cell> _cells{static_cast<size_t >(CELL_COUNT_X * CELL_COUNT_Y)};
};
