/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** ColorTest
*/

#include <criterion/criterion.h>

#include "Graphical/Color.hpp"

Test(Color, contructor)
{
    Color color1(125, 75, 25);

    cr_assert_eq(color1.r, 125);
    cr_assert_eq(color1.g, 75);
    cr_assert_eq(color1.b, 25);
    cr_assert_eq(color1.a, 255);
}

Test(Color, getter)
{
    Color color(0xf5, 0xe5, 0xa4);

    cr_assert_eq(0xf5e5a4ff, color.getValue());
}