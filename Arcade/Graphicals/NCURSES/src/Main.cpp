/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Main.cpp
*/

#include "IGraphicalLib.hpp"
#include "Ncurses.hpp"

extern "C"
Arcade::IGraphicLib *getInstance()
{
    return new Ncurses;
}