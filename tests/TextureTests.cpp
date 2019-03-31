/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ColorTest
*/

#include <criterion/criterion.h>

#include "SFML.hpp"
#include "SDL.hpp"
#include "Centipede.hpp"
#include "CentipedeTexture.hpp"

Test(Texture, createSFMLTexture)
{
    SFML sfml;
    Arcade::ATexture *spriteSheet = sfml.createTexture(SPRITE_SHEET, sizeof(SPRITE_SHEET));

    cr_assert_eq(spriteSheet->getBuffer(), SPRITE_SHEET);
    cr_assert_eq(spriteSheet->getBufferLength(), sizeof(SPRITE_SHEET));
    spriteSheet->~ATexture();
}

Test(Texture, createSDLTexture)
{
    SDL sdl;
    Arcade::ATexture *spriteSheet = sdl.createTexture(SPRITE_SHEET, sizeof(SPRITE_SHEET));

    cr_assert_eq(spriteSheet->getBuffer(), SPRITE_SHEET);
    cr_assert_eq(spriteSheet->getBufferLength(), sizeof(SPRITE_SHEET));
}