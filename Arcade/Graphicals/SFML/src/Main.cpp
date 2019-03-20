/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Main.cpp
*/

#include "IGraphicalLib.hpp"
#include "SFML.hpp"

extern "C"
Arcade::IGraphicLib *getInstance()
{
    return new SFML;
}