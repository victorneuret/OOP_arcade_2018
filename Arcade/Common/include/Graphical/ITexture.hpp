/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** ITexture.hpp
*/

#pragma once

#include <string>

#include "Graphical/Color.hpp"

class ITexture {
public:
    ITexture(const std::string &path, const Color &fallbackColor);
    ITexture(const void *memory, const Color &fallbackColor);
    virtual ~ITexture() = default;

    virtual void render() = 0;
};