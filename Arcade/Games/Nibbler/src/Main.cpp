/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Main.cpp
*/

#include "IGame.hpp"
#include "Nibbler.hpp"

extern "C"
Arcade::IGame *getGameInstance()
{
    return new Nibbler;
}
