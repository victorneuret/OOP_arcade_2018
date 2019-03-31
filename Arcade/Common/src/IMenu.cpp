/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** IMenu.cpp
*/

#include "IMenu.hpp"

Arcade::IMenu::CoreExtension::CoreExtension(const std::vector<std::string> &gameList,
                                            const std::vector<std::string> &libList,
                                            const std::string &loadedLibraryPath,
                                            const std::function<void (const std::string &)> &loadGamePtr,
                                            const std::function<void (const std::string &)> &loadGraphicalPtr) noexcept
    : games(gameList), libs(libList), loadedLibrary(loadedLibraryPath), loadGame(loadGamePtr), loadGraphical(loadGraphicalPtr)
{}
