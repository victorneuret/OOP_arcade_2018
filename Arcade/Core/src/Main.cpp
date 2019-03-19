/*
** EPITECH PROJECT, 2019
** arcade
** File description:
** Main.cpp
*/

#include <string>
#include <iostream>
#include <unistd.h>

#include "Core.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    try {
        Core c(av[1]);
//        c.loadDirectory(LIB_PATH);
//        c.loadDirectory(GAME_PATH);
        while (true) {
            if (!c.tick())
                break;
            c.render();
        }
    } catch (std::exception &error) {
        std::cerr << error.what() << std::endl;
        return 84;
    }
    return 0;
}