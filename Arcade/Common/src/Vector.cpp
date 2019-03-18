/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Vector.cpp
*/

#include "Math/Vector.hpp"

Vector::Vector(double x, double y) noexcept
        : x(x), y(y)
{}

Vector &Vector::operator+=(const Vector &vec) noexcept
{
    x += vec.x;
    y += vec.y;
    return *this;
}

Vector &Vector::operator+=(const double &val) noexcept
{
    x += val;
    y += val;
    return *this;
}

Vector &Vector::operator-=(const Vector &vec) noexcept
{
    x -= vec.x;
    y -= vec.y;
    return *this;
}

Vector &Vector::operator-=(const double &val) noexcept
{
    x -= val;
    y -= val;
    return *this;
}

Vector &Vector::operator*=(const Vector &vec) noexcept
{
    x *= vec.x;
    y *= vec.y;
    return *this;
}

Vector &Vector::operator*=(const double &val) noexcept
{
    x *= val;
    y *= val;
    return *this;
}

Vector &Vector::operator/=(const Vector &vec) noexcept
{
    x /= vec.x;
    y /= vec.y;
    return *this;
}

Vector &Vector::operator/=(const double &val) noexcept
{
    x /= val;
    y /= val;
    return *this;
}

Vector Vector::operator+(const Vector &vec) const noexcept
{
    return Vector(x + vec.x, y + vec.y);
}

Vector Vector::operator+(const double &val) const noexcept
{
    return Vector(x + val, y + val);
}

Vector Vector::operator-(const Vector &vec) const noexcept
{
    return Vector(x - vec.x, y - vec.y);
}

Vector Vector::operator-(const double &val) const noexcept
{
    return Vector(x - val, y - val);
}

Vector Vector::operator*(const Vector &vec) const noexcept
{
    return Vector(x * vec.x, y * vec.y);
}

Vector Vector::operator*(const double &val) const noexcept
{
    return Vector(x * val, y * val);
}

Vector Vector::operator/(const Vector &vec) const noexcept
{
    return Vector(x / vec.x, y / vec.y);
}

Vector Vector::operator/(const double &val) const noexcept
{
    return Vector(x / val, y / val);
}

Vector &Vector::operator=(const Vector &vec) noexcept
{
    x = vec.x;
    y = vec.y;
    return *this;
}

Vector &Vector::operator=(const double &val) noexcept
{
    x = val;
    y = val;
    return *this;
}

bool Vector::operator==(const Vector &vec) const noexcept
{
    return (x == vec.x && y == vec.y);
}

bool Vector::operator!=(const Vector &vec) const noexcept
{
    return (x != vec.x || y != vec.y);
}
