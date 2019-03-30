/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** MainMenu.hpp
*/

#pragma once

#include <unordered_map>
#include <functional>

#include "IMenu.hpp"
#include "IGame.hpp"
#include "IGraphicalLib.hpp"
#include "Graphical/ASprite.hpp"

constexpr const char * const LIB_PREFIX = "/lib_arcade_";
constexpr const uint8_t PSEUDO_SIZE = 3;

class MainMenu final : public Arcade::IMenu {
public:
    enum SELECTION_TYPE {
        SELECT_GAME,
        SELECT_LIB,
        SELECT_PSEUDO
    };

    struct Pseudo {
        char name[PSEUDO_SIZE] = {'A', 'A', 'A'};
        uint8_t index = 0;
        bool selected = false;
    };

    MainMenu();
    MainMenu(const MainMenu &) = delete;
    ~MainMenu() override = default;

    MainMenu &operator=(const MainMenu &) = delete;

    void init(Arcade::IGraphicLib *graphic) override;
    void tick(Arcade::IGraphicLib *graphic, double deltaTime) override;
    void tick(Arcade::IGraphicLib *graphic, double deltaTime, const CoreExtension &core) override;
    void render(Arcade::IGraphicLib *graphic) override;
    void render(Arcade::IGraphicLib *graphic, const CoreExtension &core) override;
    bool isCloseRequested() const noexcept override;
    void reloadResources(Arcade::IGraphicLib *) override;

private:
    using MainMenuPtr = void (MainMenu::*)();

    void moveUp(const CoreExtension &core);
    void moveDown(const CoreExtension &core);
    void moveLeft(const CoreExtension &core);
    void moveRight(const CoreExtension &core);
    void primaryPressed(const CoreExtension &core);
    static const std::string getLibName(const std::string &path);
    void onChange(const CoreExtension &core) noexcept;

    const Arcade::Color _selectedColor = Arcade::Color(255, 255, 255);
    const Arcade::Color _unselectedColor = Arcade::Color(100, 100, 100);

    const std::unordered_map<uint8_t, std::function<void (const CoreExtension &)>> _gameKeys = {
        {Arcade::IGraphicLib::UP, std::bind(&MainMenu::moveUp, this, std::placeholders::_1)},
        {Arcade::IGraphicLib::DOWN, std::bind(&MainMenu::moveDown, this, std::placeholders::_1)},
        {Arcade::IGraphicLib::LEFT, std::bind(&MainMenu::moveLeft, this, std::placeholders::_1)},
        {Arcade::IGraphicLib::RIGHT, std::bind(&MainMenu::moveRight, this, std::placeholders::_1)},
        {Arcade::IGraphicLib::PRIMARY, std::bind(&MainMenu::primaryPressed, this, std::placeholders::_1)}
    };

    std::pair<uint8_t, uint8_t> _selection{SELECT_GAME, 1};
    Pseudo _pseudo;
    double _time = 0;
    double _speed = 0.1;
};
