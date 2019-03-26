/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Main.cpp
*/

#include "IGraphicalLib.hpp"
#include "SFML.hpp"
#include "SFMLTexture.hpp"
#include "SFMLSprite.hpp"

extern "C"
Arcade::IGraphicLib *getInstance()
{
    return new SFML;
}