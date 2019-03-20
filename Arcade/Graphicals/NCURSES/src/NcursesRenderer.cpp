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
    initscr();
    noecho();
    curs_set(0);
    timeout(0);
    nocbreak();
    start_color();
    keypad(stdscr, TRUE);
}

NcursesRenderer::~NcursesRenderer()
{
    endwin();
}

void NcursesRenderer::drawRectangle(const Arcade::Rect &rect, const Arcade::Color &color, bool fill)
{
    WINDOW *win = newwin(static_cast<int> (LINES * rect.size.y), static_cast<int>(COLS * rect.size.x),
        static_cast<int>(LINES * rect.pos.y), static_cast<int>(COLS * rect.pos.x));

    _initColor(color, fill);
    box(win, 0, 0);
    wbkgd(win, COLOR_PAIR(_colorIndex));
    wrefresh(win);
    werase(win);
}

void NcursesRenderer::drawTexture(const std::string &, const Arcade::Vector &)
{}

void NcursesRenderer::drawText(const std::string &text, uint8_t, const Arcade::Vector &pos, const Arcade::Color &color)
{
    _initColor(color);
    attron(COLOR_PAIR(_colorIndex));
    mvprintw(static_cast<int>(LINES * pos.y), static_cast<int>(COLS * pos.x), text.c_str());
    attroff(COLOR_PAIR(_colorIndex));
}

void NcursesRenderer::display()
{
    refresh();
}

void NcursesRenderer::clear()
{
    _colorIndex = 0;
    erase();
}

void NcursesRenderer::_initColor(const Arcade::Color &color, bool fill) noexcept
{
    init_color(++_colorIndex, static_cast<short>(color.r * 1000 / 255),
        static_cast<short>(color.g * 1000 / 255),
        static_cast<short>(color.b * 1000 / 255));
    init_pair(_colorIndex, _colorIndex, static_cast<short>(fill ? _colorIndex : COLOR_BLACK));
}
