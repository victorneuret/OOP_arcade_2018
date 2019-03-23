/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** ASprite.hpp
*/

#pragma once

#include <memory>

#include "Math/Rect.hpp"
#include "ATexture.hpp"

namespace Arcade {
    class ASprite {
    public:
        // If rect == Rect(0, 0, 0, 0): load the whole texture.
        ASprite(const std::shared_ptr<ATexture> &texture,
                const Vector &pos,
                const Rect &rect = Rect());
        virtual ~ASprite() = default;

        virtual void setPosition(const Vector &newPos) = 0;
        virtual void setTextureRect(const Rect &newRect) = 0;
        virtual const std::shared_ptr<ATexture> &getTexture() const noexcept final;
    protected:
        const std::shared_ptr<ATexture> _texture;
        Vector _pos;
        Rect _rect;
    };
}
