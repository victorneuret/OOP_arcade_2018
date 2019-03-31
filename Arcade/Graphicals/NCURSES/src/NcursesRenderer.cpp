/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** NcursesRenderer.cpp
*/

#include <stdexcept>

#include "NcursesRenderer.hpp"

NcursesRenderer::NcursesRenderer()
{
    if (!initscr())
        throw std::runtime_error("Failed to create Ncurses window");
    if (noecho() == ERR || nodelay(stdscr, true) == ERR || curs_set(0) == ERR || keypad(stdscr, TRUE) == ERR)
        throw std::runtime_error("Failed to initialize Ncurses window");
    timeout(0);
    if (start_color() == ERR)
        throw std::runtime_error("Failed to initialize color");
    _win = newwin(_height, _width, (LINES / 2) - (_height / 2), (COLS / 2) - (_width / 2));
    if (!_win)
        throw std::runtime_error("Failed to create Ncurses window");
}

NcursesRenderer::~NcursesRenderer()
{
    erase();
    refresh();
    delwin(_win);
    endwin();
}

void NcursesRenderer::drawRectangle(const Arcade::Rect &rect, const Arcade::Color &color, bool fill)
{
    _initColor(color, fill);

    wattron(_win, COLOR_PAIR(_colorIndex));
    for (auto y = 0; y < (rect.size.y * _height); y++) {
        for (auto x = 0; x < (rect.size.x * _width); x++) {
            mvwaddch(_win, (rect.pos.y * _height) + y, (rect.pos.x * _width) + x, 0);
        }
    }
    wattroff(_win, COLOR_PAIR(_colorIndex));
}

void NcursesRenderer::drawSprite(const Arcade::ASprite *sprite)
{
    drawRectangle(sprite->getPosAndSize(), sprite->getFallbackColor(), true);
}

void NcursesRenderer::drawText(const std::string &text, uint8_t, const Arcade::Vector &pos, const Arcade::Color &color)
{
    _initColor(color);
    wattron(_win, COLOR_PAIR(_colorIndex));
    mvwaddstr(_win, static_cast<int>(_height * pos.y),
        static_cast<int>(_width * pos.x), text.c_str());
    wattroff(_win, COLOR_PAIR(_colorIndex));
}

void NcursesRenderer::display()
{
    wnoutrefresh(_win);
    doupdate();
}

void NcursesRenderer::clear()
{
    werase(_win);
    mvwin(_win, (LINES / 2) - (_height / 2), (COLS / 2) - (_width / 2));
    wresize(_win, _height, _width);
    _colorIndex = 0;
}

void NcursesRenderer::_initColor(const Arcade::Color &color, bool fill) noexcept
{
    init_color(++_colorIndex, static_cast<short>(color.r * 1000 / 255),
        static_cast<short>(color.g * 1000 / 255),
        static_cast<short>(color.b * 1000 / 255));
    init_pair(_colorIndex, _colorIndex, static_cast<short>(fill ? _colorIndex : COLOR_BLACK));
}
