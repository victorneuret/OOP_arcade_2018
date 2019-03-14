/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** IGraphicalLib.hpp
*/

#pragma once

#include <cstdint>

#include "IRenderer.hpp"

class IGraphicLib {
public:
	enum Key {
		UP = (1 << 0),
		DOWN = (1 << 1),
		LEFT = (1 << 2),
		RIGHT = (1 << 3),
		PRIMARY = (1 << 4),
		SECONDARY = (1 << 5),
		START = (1 << 6),
		SELECT = (1 << 7)
	};

	virtual IGraphicLib();
	virtual ~IGraphicLib() = default;

	virtual uint8_t getKeyState() const noexcept = 0;
	virtual void sendKeyInput(Key input) const noexcept = 0;
	virtual IRenderer &getRenderer() const noexcept = 0;
	virtual bool isCloseRequested() const noexcept = 0;
};