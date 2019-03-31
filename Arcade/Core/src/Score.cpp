/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Score.cpp
*/

#include <stdexcept>
#include <iostream>
#include <filesystem>
#include <sstream>
#include <string.h>
#include <algorithm>

#include "Score.hpp"

Arcade::Score::UserScore::UserScore(char *username, size_t newScore)
    : name(), score(newScore)
{
    strncpy(name, username, 3);
}

bool Arcade::Score::UserScore::operator==(const Arcade::Score::UserScore &otherScore) const noexcept
{
    return (name == std::string(otherScore.name));
}

bool Arcade::Score::UserScore::operator>(const Arcade::Score::UserScore &otherScore) const noexcept
{
    return (score > otherScore.score);
}

Arcade::Score::Score(const std::string &path)
    : _path(path), _scores()
{
    std::ifstream file(_path);
    std::string line;

    if (!file.is_open())
        return;

    while (!file.eof() && file.good() && std::getline(file, line)) {
        std::stringstream lineStream(line);
        char gameName[GAME_NAME_LEN];

        lineStream >> gameName;
        while (!lineStream.eof() && lineStream.good()) {
            UserScore newScore(nullptr, 0);

            lineStream >> newScore.name >> newScore.score;
            if (!lineStream.fail() || !(*newScore.name) || newScore.score <= 0) {
                if (_scores.find(gameName) == _scores.end())
                    _scores[gameName] = {};
                _scores[gameName].push_back(newScore);
            }
        }
    }
}

Arcade::Score::~Score() noexcept(false)
{
    if (!hasChanged)
        return;

    std::ofstream file(_path, std::ofstream::out | std::ofstream::trunc);

    if (!file.is_open())
        throw std::runtime_error("Failed to open score file: " + _path);

    for (const auto &key : _scores) {
        file << key.first;
        for (const auto &c : key.second)
            file << c.name << c.score;
        file << std::endl;
    }
}

const std::unordered_map<std::string, std::vector<Arcade::Score::UserScore>> &Arcade::Score::getScores() const noexcept
{
    return _scores;
}

void Arcade::Score::addScore(const std::string &game, const UserScore &newScore) noexcept
{
    if (!(*newScore.name) || newScore.score == 0)
        return;

    if (_scores.find(game) != _scores.end()) {
        for (auto &c : _scores[game]) {
            if (newScore == c) {
                if (newScore > c) {
                    c.score = newScore.score;
                    hasChanged = true;
                }
                return;
            }
        }
    }
    hasChanged = true;
    _scores[game].push_back(newScore);
}