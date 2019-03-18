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
    start_color();
    keypad(stdscr, TRUE);
    if (has_colors() == FALSE)
        throw std::runtime_error("Your terminal does not support color");
}

NcursesRenderer::~NcursesRenderer()
{
    endwin();
    refresh();
}

void NcursesRenderer::drawRectangle(const Rect &rect, const Color &color, bool fill)
{
    WINDOW *win = newwin((int)rect.size.y, (int)rect.size.x, (int)rect.pos.y, (int)rect.pos.x);

    _init_color(color, fill);
    box(win, 0, 0);
    wbkgd(win, COLOR_PAIR(1));
}

void NcursesRenderer::drawLine(const Vector &start, const Vector &end, const Color &color)
{
    _init_color(color);
    attron(COLOR_PAIR(1));
    if (start.y == end.y)
        mvhline(start.y, start.x, 0, end.x - start.x);
    else
        mvvline(start.y, start.y, 0, end.y - start.y);
    attroff(COLOR_PAIR(1));
}

void NcursesRenderer::drawTexture(const std::string &, const Vector &)
{}

void NcursesRenderer::drawText(const std::string &text, uint8_t, const Vector &pos, const Color &color)
{
    _init_color(color);
    attron(COLOR_PAIR(1));
    mvprintw((int)pos.y, (int)pos.x, text.c_str());
    attroff(COLOR_PAIR(1));
}

void NcursesRenderer::display()
{
    refresh();
}

void NcursesRenderer::clear()
{
    ::clear();
}

void NcursesRenderer::_init_color(const Color &color, bool fill) const noexcept
{
    init_color(1, (short)(color.r * 4), (short)(color.g * 4), (short)(color.b * 4));
    init_pair(1, 1, (short)(fill ? 1 : COLOR_BLACK));
}