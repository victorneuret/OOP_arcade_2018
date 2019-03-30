/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Main.cpp
*/

#include "SFML.hpp"
#include "IGraphicalLib.hpp"

extern "C"
Arcade::IGraphicLib *getGraphicalInstance()
{
    return new SFML;
}
