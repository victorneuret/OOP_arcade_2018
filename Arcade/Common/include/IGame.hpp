/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** IGame.hpp
*/

#pragma once

class IGame {
public:
	IGame();
	virtual ~IGame() = default;

	virtual bool tick() = 0;
	virtual bool render() = 0;
	virtual bool isCloseRequested() const noexcept = 0;
};