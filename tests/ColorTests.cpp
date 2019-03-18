/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Color-test.c
*/

#include <criterion/criterion.h>

#include "include/Graphical/Color.hpp"

Test(Color, contructor)
{
    Color color1(125, 75, 25);

    cr_assert_eq(color1.r, 125);
    cr_assert_eq(color1.g, 75);
    cr_assert_eq(color1.b, 25);
    cr_assert_eq(color1.a, 255);
}