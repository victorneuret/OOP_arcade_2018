/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Vector.cpp
*/

#include <stdexcept>
#include "Math/Vector.hpp"

Arcade::Vector::Vector(double x, double y) noexcept
    : x(x), y(y)
{}

Arcade::Vector &Arcade::Vector::operator+=(const Vector &vec) noexcept
{
    x += vec.x;
    y += vec.y;
    return *this;
}

Arcade::Vector &Arcade::Vector::operator+=(const double &val) noexcept
{
    x += val;
    y += val;
    return *this;
}

Arcade::Vector &Arcade::Vector::operator-=(const Vector &vec) noexcept
{
    x -= vec.x;
    y -= vec.y;
    return *this;
}

Arcade::Vector &Arcade::Vector::operator-=(const double &val) noexcept
{
    x -= val;
    y -= val;
    return *this;
}

Arcade::Vector &Arcade::Vector::operator*=(const Vector &vec) noexcept
{
    x *= vec.x;
    y *= vec.y;
    return *this;
}

Arcade::Vector &Arcade::Vector::operator*=(const double &val) noexcept
{
    x *= val;
    y *= val;
    return *this;
}

Arcade::Vector &Arcade::Vector::operator/=(const Vector &vec)
{
    if (vec.x == 0 || vec.y == 0)
        throw std::runtime_error("Division by 0");
    x /= vec.x;
    y /= vec.y;
    return *this;
}

Arcade::Vector &Arcade::Vector::operator/=(const double &val)
{
    if (val == 0)
        throw std::runtime_error("Division by 0");
    x /= val;
    y /= val;
    return *this;
}

Arcade::Vector Arcade::Vector::operator+(const Vector &vec) const noexcept
{
    return Vector(x + vec.x, y + vec.y);
}

Arcade::Vector Arcade::Vector::operator+(const double &val) const noexcept
{
    return Vector(x + val, y + val);
}

Arcade::Vector Arcade::Vector::operator-(const Vector &vec) const noexcept
{
    return Vector(x - vec.x, y - vec.y);
}

Arcade::Vector Arcade::Vector::operator-(const double &val) const noexcept
{
    return Vector(x - val, y - val);
}

Arcade::Vector Arcade::Vector::operator*(const Vector &vec) const noexcept
{
    return Vector(x * vec.x, y * vec.y);
}

Arcade::Vector Arcade::Vector::operator*(const double &val) const noexcept
{
    return Vector(x * val, y * val);
}

Arcade::Vector Arcade::Vector::operator/(const Vector &vec) const
{
    if (vec.x == 0 || vec.y == 0)
        throw std::runtime_error("Division by 0");
    return Vector(x / vec.x, y / vec.y);
}

Arcade::Vector Arcade::Vector::operator/(const double &val) const
{
    if (val == 0)
        throw std::runtime_error("Division by 0");
    return Vector(x / val, y / val);
}

Arcade::Vector &Arcade::Vector::operator=(const Vector &vec) noexcept
{
    x = vec.x;
    y = vec.y;
    return *this;
}

Arcade::Vector &Arcade::Vector::operator=(const double &val) noexcept
{
    x = val;
    y = val;
    return *this;
}

bool Arcade::Vector::operator==(const Vector &vec) const noexcept
{
    return (x == vec.x && y == vec.y);
}

bool Arcade::Vector::operator!=(const Vector &vec) const noexcept
{
    return (x != vec.x || y != vec.y);
}
