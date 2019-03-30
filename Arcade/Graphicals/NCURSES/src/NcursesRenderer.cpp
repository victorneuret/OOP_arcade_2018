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
    if (!stdscr)
        throw std::runtime_error("Failed to create Ncurses window");
    noecho();
    curs_set(0);
    timeout(0);
    if (start_color())
        throw std::runtime_error("Failed to initialize color");
    keypad(stdscr, TRUE);
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
    WINDOW *tmpWin = derwin(_win, static_cast<int>(_height * rect.size.y),
        static_cast<int>(_width * rect.size.x), static_cast<int>(_height * rect.pos.y),
        static_cast<int>(_width * rect.pos.x));

    if (!tmpWin)
        throw std::runtime_error("Failed to create Ncurses rectangle");
    _initColor(color, fill);
    box(tmpWin, 0, 0);
    if (wbkgd(tmpWin, COLOR_PAIR(_colorIndex)))
        throw std::runtime_error("Failed to set rectangle color");
    wnoutrefresh(tmpWin);
    werase(tmpWin);
    delwin(tmpWin);
}

void NcursesRenderer::drawSprite(const Arcade::ASprite &sprite)
{
    drawRectangle(sprite.getPosAndSize(), sprite.getFallbackColor(), true);
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
    std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 24));
}

void NcursesRenderer::clear()
{
    if (werase(_win) == ERR)
        throw std::runtime_error("Failed to clear window");
    wmove(_win, (LINES / 2) - (_height / 2), (COLS / 2) - (_width / 2));
    _colorIndex = 0;
}

void NcursesRenderer::_initColor(const Arcade::Color &color, bool fill) noexcept
{
    init_color(++_colorIndex, static_cast<short>(color.r * 1000 / 255),
        static_cast<short>(color.g * 1000 / 255),
        static_cast<short>(color.b * 1000 / 255));
    init_pair(_colorIndex, _colorIndex, static_cast<short>(fill ? _colorIndex : COLOR_BLACK));
}
