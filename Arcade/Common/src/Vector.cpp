/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Vector.cpp
*/

#include <stdexcept>
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

Vector &Vector::operator/=(const Vector &vec)
{
    if (vec.x == 0 || vec.y == 0)
        throw std::runtime_error("Division by 0");
    x /= vec.x;
    y /= vec.y;
    return *this;
}

Vector &Vector::operator/=(const double &val) noexcept
{
    if (val == 0)
        throw std::runtime_error("Division by 0");
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
    if (vec.x == 0 || vec.y == 0)
        throw std::runtime_error("Division by 0");
    return Vector(x / vec.x, y / vec.y);
}

Vector Vector::operator/(const double &val) const noexcept
{
    if (val == 0)
        throw std::runtime_error("Division by 0");
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
