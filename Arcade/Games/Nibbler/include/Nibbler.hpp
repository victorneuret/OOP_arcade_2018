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

#include "IGame.hpp"
#include "IGraphicalLib.hpp"

constexpr const uint8_t MAP_WIDTH = 20;
constexpr const uint8_t MAP_HIGH = 19;

typedef struct snake_s {
    Arcade::Vector head;
    Arcade::Vector tail;
    std::vector<Arcade::Vector> body;
} snake_t;

class Nibbler final : public Arcade::IGame {
public:
    Nibbler() = default;
    ~Nibbler() override = default;

    void tick(Arcade::IGraphicLib *graphic) override;
    void render(Arcade::IGraphicLib *graphic) override;
    bool isCloseRequested() const noexcept override;
    void reloadResources(Arcade::IGraphicLib *) override;

private:
    char _maps[MAP_HIGH][MAP_WIDTH] = {
        "###################",
        "#  @   @   @   @  #",
        "# ### # ### # ### #",
        "#@# #@#     #@# #@#",
        "# ### # # # # ### #",
        "#     #@# #@#     #",
        "# ##### # # ##### #",
        "#@# @         @ #@#",
        "# # #####@##### # #",
        "#   @         @   #",
        "# ##### ### ##### #",
        "#  @    # #    @  #",
        "# ### # ### # ### #",
        "# # # #  @  # # # #",
        "# ### # ### # ### #",
        "#@   @#@# #@#@   @#",
        "#@##### ### #####@#",
        "#                 #",
        "###################"
    };
    snake_t _snake = {
        {11, 17},
        {7, 17},
        {
            {10, 17},
            {9, 17},
            {8, 17}
        }
    };
    /*Arcade::Vector _tailPos = Arcade::Vector(7, 17);
    Arcade::Vector _headPos = Arcade::Vector(11, 17);
    std::vector<Arcade::Vector> _snake = {
        {11, 17},
        {10, 17},
        {9, 17},
        {8, 17},
        {7, 17}
    };*/
    void drawMap(Arcade::IGraphicLib *graphic);
    void drawSnake(Arcade::IGraphicLib *graphic);

    void move(const Arcade::Vector &head);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    const std::unordered_map<uint8_t, std::function<void ()>> _gameKeys = {
            {Arcade::IGraphicLib::UP, std::bind(&Nibbler::moveUp, this)},
            {Arcade::IGraphicLib::DOWN, std::bind(&Nibbler::moveDown, this)},
            {Arcade::IGraphicLib::LEFT, std::bind(&Nibbler::moveLeft, this)},
            {Arcade::IGraphicLib::RIGHT, std::bind(&Nibbler::moveRight, this)}
    };
};
