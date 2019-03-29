/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** NcursesTexture.cpp
*/

#include "NcursesTexture.hpp"

NcursesTexture::NcursesTexture(const void *buffer, const size_t &len, const Arcade::Color &fallbackColor)
    : ATexture(buffer, len, fallbackColor)
{}