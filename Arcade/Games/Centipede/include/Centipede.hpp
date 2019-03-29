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
constexpr uint64_t CELL_COUNT = static_cast<uint64_t >(CELL_COUNT_X * CELL_COUNT_Y);

constexpr double OBSTACLE_PERCENTAGE = 5.0;

constexpr double SHOT_SPEED = 1.75;
constexpr double SHOT_WIDTH = PLAYER_WIDTH / 6.0;
constexpr double SHOT_HEIGHT = PLAYER_HEIGHT;

static const Arcade::Rect PLAYER_SPRITE_RECT{20, 9, 9, 8};

static const Arcade::Rect DESTROYED_OBSTACLE{90, 108, 8, 8};

static const Arcade::Rect OBSTACLE_SPRITE_RECTS[] = {
    Arcade::Rect{95, 72, 8, 8},
    Arcade::Rect{86, 72, 8, 8},
    Arcade::Rect{77, 72, 8, 8},
    Arcade::Rect{77, 72, 8, 8}, // Four sprites for five states...
    Arcade::Rect{68, 72, 8, 8}
};

class Centipede final : public Arcade::IGame {
public:
    Centipede();
    Centipede(const Centipede &) = delete;
    ~Centipede() override;

    Centipede &operator=(const Centipede &) = delete;

    void init(Arcade::IGraphicLib *graphic) override;
    void tick(Arcade::IGraphicLib *graphic, double deltaTime) override;
    void render(Arcade::IGraphicLib *graphic) override;
    bool isCloseRequested() const noexcept override;
    void reloadResources(Arcade::IGraphicLib *lib) override;

private:
    struct Cell {
        Arcade::Rect rect{0, 0, CELL_SIZE, CELL_SIZE};
        bool hasObstacle = false;
        uint8_t obstacleHealth = 5;

        Arcade::ASprite *sprite = nullptr;
    };

    static void _updateObstacle(Cell &cell);
    static bool _rectanglesCollide(const Arcade::Rect &rectA, const Arcade::Rect &rectB);

    void _checkShotCollision();

    void _shoot();
    void _moveUp();
    void _moveDown();
    void _moveLeft();
    void _moveRight();

    void _freeResources();

    const std::unordered_map<Arcade::IGraphicLib::GameKey, std::function<void()>> _gameKeys = {
        {Arcade::IGraphicLib::UP,      std::bind(&Centipede::_moveUp, this)},
        {Arcade::IGraphicLib::DOWN,    std::bind(&Centipede::_moveDown, this)},
        {Arcade::IGraphicLib::LEFT,    std::bind(&Centipede::_moveLeft, this)},
        {Arcade::IGraphicLib::RIGHT,   std::bind(&Centipede::_moveRight, this)},
        {Arcade::IGraphicLib::PRIMARY, std::bind(&Centipede::_shoot, this)}
    };

    bool _closeRequested = false;
    double _deltaTime = 0;

    Arcade::Vector _playerPos{0.5, 0.9};
    std::vector<Cell> _cells{static_cast<size_t >(CELL_COUNT_X * CELL_COUNT_Y)};

    Arcade::ATexture *_spriteSheet = nullptr;
    Arcade::ASprite *_playerSprite = nullptr;

    bool _isShooting = false;
    Arcade::Vector _shotPos{0, 0};
};