/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** NcursesRenderer.cpp
*/

#include <stdexcept>
#include <thread>
#include <chrono>

#include "NcursesRenderer.hpp"

NcursesRenderer::NcursesRenderer()
{
    initscr();
    noecho();
    curs_set(0);
    timeout(0);
    nocbreak();
    start_color();
    keypad(stdscr, TRUE);
    _size = LINES > COLS ? COLS : LINES;
    _win = newwin(_size, _size, LINES / 2 - (_size / 2), COLS / 2 - (_size / 2));
}

NcursesRenderer::~NcursesRenderer()
{
    delwin(_win);
    endwin();
}

void NcursesRenderer::drawRectangle(const Arcade::Rect &rect, const Arcade::Color &color, bool fill)
{
    WINDOW *tmpWin = derwin(_win, static_cast<int>(_size * rect.size.y),
        static_cast<int>(_size* rect.size.x), static_cast<int>(_size * rect.pos.y),
        static_cast<int>(_size * rect.pos.x));

    _initColor(color, fill);
    box(tmpWin, 0, 0);
    wbkgd(tmpWin, COLOR_PAIR(_colorIndex));
    wnoutrefresh(tmpWin);
    werase(tmpWin);
    delwin(tmpWin);
}

void NcursesRenderer::drawTexture(const std::string &, const Arcade::Vector &)
{}

void NcursesRenderer::drawText(const std::string &text, uint8_t, const Arcade::Vector &pos, const Arcade::Color &color)
{
    _initColor(color);
    wattron(_win, COLOR_PAIR(_colorIndex));
    mvwaddstr(_win, static_cast<int>(_size * pos.y),
        static_cast<int>(_size * pos.x), text.c_str());
    wattroff(_win, COLOR_PAIR(_colorIndex));
}

void NcursesRenderer::display()
{
    wnoutrefresh(_win);
    doupdate();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 24));
}

void NcursesRenderer::clear()
{
    werase(_win);
    if (_size != (LINES > COLS ? COLS : LINES)) {
        _size = LINES > COLS ? COLS : LINES;
        wresize(_win, _size, _size);
        wmove(_win, LINES / 2 - (_size / 2), COLS / 2 - (_size / 2));
    }
    _colorIndex = 0;
}

void NcursesRenderer::_initColor(const Arcade::Color &color, bool fill) noexcept
{
    init_color(++_colorIndex, static_cast<short>(color.r * 1000 / 255),
        static_cast<short>(color.g * 1000 / 255),
        static_cast<short>(color.b * 1000 / 255));
    init_pair(_colorIndex, _colorIndex, static_cast<short>(fill ? _colorIndex : COLOR_BLACK));
}
