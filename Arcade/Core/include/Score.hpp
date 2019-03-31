/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Score.hpp
*/

#pragma once

#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>

constexpr const size_t GAME_NAME_LEN = 20;

namespace Arcade {
    class Score final {
    public:
        struct UserScore {
            char name[3];
            size_t score;

            UserScore(char *username, size_t newScore);
            bool operator==(const UserScore &otherScore) const noexcept;
            bool operator>(const UserScore &otherScore) const noexcept;
        };

        Score(const std::string &path);
        ~Score() noexcept(false);

        const std::unordered_map<std::string, std::vector<UserScore>> &getScores() const noexcept;
        void addScore(const std::string &game, const UserScore &newScore) noexcept;

    private:
        const std::string _path;
        bool hasChanged = false;
        std::unordered_map<std::string, std::vector<UserScore>> _scores;
    };
}
