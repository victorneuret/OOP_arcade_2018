/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** NcursesSprite.hpp
*/

#pragma once

#include "Graphical/ASprite.hpp"

class NcursesSprite : public Arcade::ASprite {
public:
    NcursesSprite(const Arcade::ATexture *texture, const Arcade::Rect &spriteSheetRect, const Arcade::Rect &posAndSize);
    ~NcursesSprite() override = default;

    NcursesSprite(const ASprite &sprite) = delete;
    ASprite &operator=(const ASprite &sprite) override = delete;

    void setPosAndSize(const Arcade::Rect &posAndSize) override;
    void setTextureRect(const Arcade::Rect &newRect) override;
};

