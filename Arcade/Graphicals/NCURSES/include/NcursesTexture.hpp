/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** NcursesTexture.hpp
*/

#pragma once

#include "Graphical/ATexture.hpp"

class NcursesTexture : public Arcade::ATexture {
public:
    NcursesTexture(const void *buffer, const size_t &len);
    ~NcursesTexture() override = default;
};
