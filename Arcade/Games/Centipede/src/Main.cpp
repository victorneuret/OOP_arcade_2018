/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Main.cpp
*/

#include "IGame.hpp"
#include "Centipede.hpp"

extern "C"
Arcade::IGame *getInstance()
{
    return new Centipede;
}