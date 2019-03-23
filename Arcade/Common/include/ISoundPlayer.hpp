/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** ISoundPlayer.hpp
*/

#pragma once

#include <string>
#include <cstdint>

namespace Arcade {
    class ISoundPlayer {
        virtual ~ISoundPlayer() = default;

        virtual void playSound(const std::string &soundPath) = 0;
        virtual void playMusic(const std::string &musicPath) = 0;
        virtual void setVolume(uint8_t value) noexcept = 0;
        virtual uint8_t getVolume() const noexcept = 0;
    };
}
