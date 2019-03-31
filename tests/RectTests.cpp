/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ColorTest
*/

#include <criterion/criterion.h>

#include "Math/Rect.hpp"

Test(Rect, vectorConstructor)
{
    Arcade::Vector pos(10, 20);
    Arcade::Vector size(30, 40);
    Arcade::Rect rect(pos, size);

    cr_assert_eq(rect.pos.x, pos.x);
    cr_assert_eq(rect.pos.y, pos.y);
    cr_assert_eq(rect.size.x, size.x);
    cr_assert_eq(rect.size.y, size.y);
}

Test(Rect, valueConstructor)
{
    Arcade::Rect rect(1, 2, 3, 4);

    cr_assert_eq(rect.pos.x, 1);
    cr_assert_eq(rect.pos.y, 2);
    cr_assert_eq(rect.size.x, 3);
    cr_assert_eq(rect.size.y, 4);
}

Test(Rect, isEqual)
{
    Arcade::Rect rect1(1, 2, 3, 4);
    Arcade::Rect rect2(1, 2, 3, 4);
    Arcade::Rect rect3(1, 1, 1, 1);

    cr_assert_eq(rect1 == rect2, true);
    cr_assert_eq(rect1 == rect3, false);
}

Test(Rect, isNotEqual)
{
    Arcade::Rect rect1(1, 2, 3, 4);
    Arcade::Rect rect2(1, 2, 3, 4);
    Arcade::Rect rect3(1, 1, 1, 1);

    cr_assert_eq(rect1 != rect2, false);
    cr_assert_eq(rect1 != rect3, true);
}

Test(Rect, operatorEqual)
{
    Arcade::Vector pos(10, 20);
    Arcade::Vector size(30, 40);
    Arcade::Rect rect(pos, size);
    Arcade::Rect rect2 = rect;

    cr_assert_eq(rect == rect2, true);
}