/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** SDL.cpp
*/

#include "SDL.hpp"

extern "C"
Arcade::IGraphicLib *getGraphicalInstance()
{
    return new SDL;
}
