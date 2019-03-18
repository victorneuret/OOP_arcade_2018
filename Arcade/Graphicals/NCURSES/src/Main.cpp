/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Main.cpp
*/

#include <ncurses.h>
#include <vector>
#include <ctime>
#include <cstdlib>

typedef struct pos_t {
    int x;
    int y;
} pos_t;

static void movePlayer(pos_t &pos, std::vector<pos_t> &map, int ch)
{
    pos_t next = pos;

    switch (ch) {
        case KEY_UP:
            next.y = (next.y - 1 < 1 ? 1 : next.y - 1) ; break;
        case KEY_DOWN:
            next.y = (next.y + 1 > LINES - 2 ? LINES - 2: pos.y + 1); break;
        case KEY_LEFT:
            next.x = (next.x - 1 < 1 ? 1 : next.x - 1); break;
        case KEY_RIGHT:
            next.x = (next.x + 1 > COLS - 2 ? COLS - 2: next.x + 1); break;
        default: break;
    }
    for (const auto &c : map) {
        if (c.x == next.x && c.y == next.y)
            return;
    }
    pos = next;
}

static std::vector<pos_t> init_map(unsigned long nb)
{
    std::vector<pos_t> vec(nb);

    std::srand(std::time(nullptr));
    for (unsigned long i = 0; i < nb; i++)
        vec.push_back((pos_t){std::rand() % (COLS - 1), std::rand() % (LINES - 1)});
    return vec;
}

static void draw_map(std::vector<pos_t> &map)
{
    for (const auto &c : map) {
        attron(COLOR_PAIR(2));
        mvprintw(c.y, c.x, "X");
        attroff(COLOR_PAIR(2));
    }
}

static void draw_player(pos_t &pos)
{
    attron(COLOR_PAIR(1));
    mvprintw(pos.y, pos.x, "O");
    attroff(COLOR_PAIR(1));
}

static WINDOW *init_window()
{
    WINDOW *win = initscr();

    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    noecho();
    curs_set(0);
    keypad(win, TRUE);
    return win;
}

void rectangle(int y1, int x1, int y2, int x2)
{
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

int main()
{
    WINDOW *win = init_window();
    std::vector<pos_t> map = init_map(20);
    pos_t pos = {COLS / 2, LINES - 2};
    int ch;

    if (!win || has_colors() == FALSE) {
        fprintf(stderr, "Error initializing ncurses.\n");
        return 84;
    }

    draw_map(map);
    draw_player(pos);
    box(win, 0, 0);
    refresh();

    while ((ch = getch()) != 'q' ) {
        wclear(win);
        rectangle(2, 2, 8, 8);
        movePlayer(pos, map, ch);
        box(win, 0, 0);
        draw_player(pos);
        draw_map(map);
        refresh();
    }
    delwin(win);
    endwin();
    refresh();
    return 0;
}