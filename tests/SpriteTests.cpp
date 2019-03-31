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

Test(Sprite, SFMLcreation)
{
    SFML sfml;
    Arcade::ATexture *spriteSheet = sfml.createTexture(SPRITE_SHEET, sizeof(SPRITE_SHEET));
    Arcade::ASprite *playerSprite = sfml.createSprite(spriteSheet, PLAYER_SPRITE_RECT, {{10, 10}, {20, 20}});

    cr_assert_eq(playerSprite->getTexture(), spriteSheet);
    cr_assert_eq(playerSprite->getSpriteSheetRect() == PLAYER_SPRITE_RECT, true);
    cr_assert_eq(playerSprite->getPosAndSize() == Arcade::Rect(10, 10, 20, 20), true);
    cr_assert_eq(playerSprite->getFallbackColor().r, 0xff);
    cr_assert_eq(playerSprite->getFallbackColor().g, 0xff);
    cr_assert_eq(playerSprite->getFallbackColor().b, 0xff);
    cr_assert_eq(playerSprite->getFallbackColor().a, 0xff);
}

Test(Sprite, SDLcreation)
{
    SDL sdl;
    Arcade::ATexture *spriteSheet = sdl.createTexture(SPRITE_SHEET, sizeof(SPRITE_SHEET));
    Arcade::ASprite *playerSprite = sdl.createSprite(spriteSheet, PLAYER_SPRITE_RECT, {{10, 10}, {20, 20}});

    cr_assert_eq(playerSprite->getTexture(), spriteSheet);
    cr_assert_eq(playerSprite->getSpriteSheetRect() == PLAYER_SPRITE_RECT, true);
    cr_assert_eq(playerSprite->getPosAndSize() == Arcade::Rect(10, 10, 20, 20), true);
    cr_assert_eq(playerSprite->getFallbackColor().r, 0xff);
    cr_assert_eq(playerSprite->getFallbackColor().g, 0xff);
    cr_assert_eq(playerSprite->getFallbackColor().b, 0xff);
    cr_assert_eq(playerSprite->getFallbackColor().a, 0xff);
}

Test(Sprite, fallbackColor)
{
    SFML sfml;
    Arcade::ATexture *spriteSheet = sfml.createTexture(SPRITE_SHEET, sizeof(SPRITE_SHEET));
    Arcade::ASprite *playerSprite = sfml.createSprite(spriteSheet, PLAYER_SPRITE_RECT, {{10, 10}, {20, 20}});

    playerSprite->setFallbackColor(Arcade::Color(0x42, 0x42, 0X42, 0x42));

    cr_assert_eq(playerSprite->getFallbackColor().r, 0x42);
    cr_assert_eq(playerSprite->getFallbackColor().g, 0x42);
    cr_assert_eq(playerSprite->getFallbackColor().b, 0x42);
    cr_assert_eq(playerSprite->getFallbackColor().a, 0x42);
}