/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** ISprite.hpp
*/

#pragma once

#include "Math/Rect.hpp"
#include "ITexture.hpp"

namespace Arcade {
    class ISprite {
    public:
        // A rectangle on position 0, 0 and of size 0, 0 loads the whole texture.
        ISprite(const ITexture &text, const Rect &rect = Rect(0, 0, 0, 0)) noexcept;
        virtual ~ISprite() = default;

        virtual void moveRect(const Rect &newRect) noexcept;
    };
}
