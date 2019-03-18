/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Main.cpp
*/

#include <string>
#include <iostream>

#include "Core.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;

    Core c(av[1]);
    c.loadDirectory(LIB_PATH);
    c.loadDirectory(GAME_PATH);

    for (unsigned int i = 0; i < 20; i++) {
        if (i > 9) {
            c.loadPrev(Core::LIBRARY);
            c.loadPrev(Core::GAME);
        } else {
            c.loadNext(Core::LIBRARY);
            c.loadNext(Core::GAME);
        }
    }
    return 0;
}