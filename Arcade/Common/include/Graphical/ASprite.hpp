/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** ASprite.hpp
*/

#pragma once

#include <functional>
#include "Math/Rect.hpp"
#include "ATexture.hpp"

namespace Arcade {
    class ASprite {
    public:
        // If spriteSheetRect == Rect(0, 0, 0, 0): load the whole texture.
        ASprite(const ATexture *texture, const Rect &spriteSheetRect, const Rect &posAndSize);
        virtual ~ASprite() = default;

        ASprite(const ASprite &) = delete;
        virtual ASprite &operator=(const ASprite &) = delete;

        virtual void setPosAndSize(const Rect &posAndSize) = 0;
        virtual void setTextureRect(const Rect &newRect) = 0;

        virtual const ATexture *getTexture() const noexcept final;
        virtual const Rect &getSpriteSheetRect() const final;
        virtual const Rect &getPosAndSize() const final;
        virtual const Color &getFallbackColor() const final;
        virtual void setFallbackColor(const Color &color) noexcept final;
    protected:
        const ATexture *_texture;
        Rect _spriteSheetRect;
        Rect _posAndSize;

        Color _fallbackColor{255, 255, 255, 255};
    };
}
