/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** VectorTests
*/

#include <criterion/criterion.h>

#include "Math/Vector.hpp"

Test(Vector, constructor)
{
    Vector vect(12, 64);

    cr_assert_eq(vect.x, 12);
    cr_assert_eq(vect.y, 64);
}

Test(Vector, OpreratorAddEqual)
{
    Vector one(1, 2);
    Vector two(3, 4);

    one += two;
    two += 2;
    cr_assert_eq(one.x, 4);
    cr_assert_eq(one.y, 6);
    cr_assert_eq(two.x, 5);
    cr_assert_eq(two.y, 6);
}

Test(Vector, OperatorMinusEqual)
{
    Vector one(1, 2);
    Vector two(3, 4);

    two -= one;
    one -= 1;
    cr_assert_eq(two.x, 2);
    cr_assert_eq(two.y, 2);
    cr_assert_eq(one.x, 0);
    cr_assert_eq(one.y, 1);
}

Test(Vector, OpreratorMultEqual)
{
    Vector one(1, 2);
    Vector two(3, 4);

    one *= two;
    two *= 2;
    cr_assert_eq(one.x, 3);
    cr_assert_eq(one.y, 8);
    cr_assert_eq(two.x, 6);
    cr_assert_eq(two.y, 8);
}

Test(Vector, OpreratorDivEqual)
{
    Vector one(1, 2);
    Vector two(3, 4);

    two /= one;
    one /= 2;
    cr_assert_eq(one.x, 0.5);
    cr_assert_eq(one.y, 1);
    cr_assert_eq(two.x, 3);
    cr_assert_eq(two.y, 2);
}

Test(Vector, OpreratorAdd)
{
    Vector one(1, 2);
    Vector two(3, 4);

    one = one + two;
    two = two + 2;
    cr_assert_eq(one.x, 4);
    cr_assert_eq(one.y, 6);
    cr_assert_eq(two.x, 5);
    cr_assert_eq(two.y, 6);
}

Test(Vector, OperatorMinus)
{
    Vector one(1, 2);
    Vector two(3, 4);

    two = two - one;
    one = one - 1;
    cr_assert_eq(two.x, 2);
    cr_assert_eq(two.y, 2);
    cr_assert_eq(one.x, 0);
    cr_assert_eq(one.y, 1);
}

Test(Vector, OpreratorMult)
{
    Vector one(1, 2);
    Vector two(3, 4);

    one = one * two;
    two = two * 2;
    cr_assert_eq(one.x, 3);
    cr_assert_eq(one.y, 8);
    cr_assert_eq(two.x, 6);
    cr_assert_eq(two.y, 8);
}

Test(Vector, OpreratorDiv)
{
    Vector one(1, 2);
    Vector two(3, 4);

    two = two / one;
    one = one / 2;
    cr_assert_eq(one.x, 0.5);
    cr_assert_eq(one.y, 1);
    cr_assert_eq(two.x, 3);
    cr_assert_eq(two.y, 2);
}

Test(Vector, OpreratorEqual)
{
    Vector one(1, 2);
    Vector two(3, 4);

    one = two;
    two = 2;
    cr_assert_eq(one.x, 3);
    cr_assert_eq(one.y, 4);
    cr_assert_eq(two.x, 2);
    cr_assert_eq(two.y, 2);
}

Test(Vector, OpreratorIsEqual)
{
    Vector one(1, 2);
    Vector two(3, 4);

    cr_assert_eq(true, one == one);
    cr_assert_eq(false, one == two);
    cr_assert_eq(true, one != two);
    cr_assert_eq(false, one != one);
}