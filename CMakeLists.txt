cmake_minimum_required(VERSION 3.13)
project(arcade)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -Weffc++")

include_directories(include)

add_library(
        lib_arcade_centipede
        SHARED
        Arcade/Games/Centipede/src/Main.cpp
)

add_library(
        lib_arcade_nibbler
        SHARED
        Arcade/Games/Nibbler/src/Main.cpp
)

add_library(
        lib_arcade_ncurses
        SHARED
        Arcade/Games/Centipede/src/Main.cpp
)

add_library(
        lib_arcade_sdl2
        SHARED
        Arcade/Games/Centipede/src/Main.cpp
)

add_library(
        lib_arcade_sfml
        SHARED
        Arcade/Games/Centipede/src/Main.cpp
)

add_executable(
        arcade
        Arcade/Core/src/Main.cpp
)
