cmake_minimum_required(VERSION 3.13)
project(arcade)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -Weffc++ -fPIC")

add_library(
        _arcade_main_menu
        SHARED
        Arcade/Games/MainMenu/src/Main.cpp
        Arcade/Common/include/Math/Rect.hpp
        Arcade/Common/include/Math/Vector.hpp
        Arcade/Common/include/IGame.hpp
        Arcade/Common/include/IGraphicalLib.hpp
        Arcade/Common/include/IRenderer.hpp
        Arcade/Common/include/Graphical/ITexture.hpp
        Arcade/Common/include/Graphical/ISprite.hpp
        Arcade/Common/include/Graphical/Color.hpp
        Arcade/Common/include/ISoundPlayer.hpp
        Arcade/Games/MainMenu/src/MainMenu.cpp
        Arcade/Games/MainMenu/include/MainMenu.hpp
)

add_library(
        _arcade_centipede
        SHARED
        Arcade/Games/Centipede/src/Main.cpp
        Arcade/Common/include/Math/Rect.hpp
        Arcade/Common/include/Math/Vector.hpp
        Arcade/Common/include/IGame.hpp
        Arcade/Common/include/IGraphicalLib.hpp
        Arcade/Common/include/IRenderer.hpp
        Arcade/Common/include/Graphical/ITexture.hpp
        Arcade/Common/include/Graphical/ISprite.hpp
        Arcade/Common/include/Graphical/Color.hpp
        Arcade/Common/include/ISoundPlayer.hpp
        Arcade/Common/src/Color.cpp
        Arcade/Common/src/Vector.cpp
        Arcade/Common/src/Rect.cpp
)

add_library(
        _arcade_nibbler
        SHARED
        Arcade/Games/Nibbler/src/Main.cpp
        Arcade/Common/include/Math/Rect.hpp
        Arcade/Common/include/Math/Vector.hpp
        Arcade/Common/include/IGame.hpp
        Arcade/Common/include/IGraphicalLib.hpp
        Arcade/Common/include/IRenderer.hpp
        Arcade/Common/include/Graphical/ITexture.hpp
        Arcade/Common/include/Graphical/ISprite.hpp
        Arcade/Common/include/Graphical/Color.hpp
        Arcade/Common/include/ISoundPlayer.hpp
        Arcade/Common/src/Color.cpp
        Arcade/Common/src/Vector.cpp
        Arcade/Common/src/Rect.cpp
        Arcade/Games/Nibbler/include/Nibbler.hpp
        Arcade/Games/Nibbler/src/Nibbler.cpp
)

add_library(
        _arcade_ncurses
        SHARED
        Arcade/Graphicals/NCURSES/src/Main.cpp
        Arcade/Common/include/Math/Rect.hpp
        Arcade/Common/include/Math/Vector.hpp
        Arcade/Common/include/IGame.hpp
        Arcade/Common/include/IGraphicalLib.hpp
        Arcade/Common/include/IRenderer.hpp
        Arcade/Common/include/Graphical/ITexture.hpp
        Arcade/Common/include/Graphical/ISprite.hpp
        Arcade/Common/include/Graphical/Color.hpp
        Arcade/Common/include/ISoundPlayer.hpp
        Arcade/Common/src/Color.cpp
        Arcade/Common/src/Vector.cpp
        Arcade/Common/src/Rect.cpp
        Arcade/Graphicals/NCURSES/src/Ncurses.cpp
        Arcade/Graphicals/NCURSES/include/Ncurses.hpp
        Arcade/Graphicals/NCURSES/src/NcursesRenderer.cpp
        Arcade/Graphicals/NCURSES/include/NcursesRenderer.hpp
)

add_library(
        _arcade_sdl2
        SHARED
        Arcade/Graphicals/SDL2/src/SDL.cpp
        Arcade/Common/include/Math/Rect.hpp
        Arcade/Common/include/Math/Vector.hpp
        Arcade/Common/include/IGame.hpp
        Arcade/Common/include/IGraphicalLib.hpp
        Arcade/Common/include/IRenderer.hpp
        Arcade/Common/include/Graphical/ITexture.hpp
        Arcade/Common/include/Graphical/ISprite.hpp
        Arcade/Common/include/Graphical/Color.hpp
        Arcade/Common/include/ISoundPlayer.hpp
        Arcade/Common/src/Color.cpp
        Arcade/Common/src/Vector.cpp
        Arcade/Common/src/Rect.cpp
        Arcade/Graphicals/SDL2/include/SDL.hpp
        Arcade/Graphicals/SDL2/include/SDLRenderer.hpp
        Arcade/Graphicals/SDL2/src/SDLRenderer.cpp
        Arcade/Graphicals/SDL2/src/Main.cpp
)

add_library(
        _arcade_sfml
        SHARED
        Arcade/Graphicals/SFML/src/Main.cpp
        Arcade/Common/include/Math/Rect.hpp
        Arcade/Common/include/Math/Vector.hpp
        Arcade/Common/include/IGame.hpp
        Arcade/Common/include/IGraphicalLib.hpp
        Arcade/Common/include/IRenderer.hpp
        Arcade/Common/include/Graphical/ITexture.hpp
        Arcade/Common/include/Graphical/ISprite.hpp
        Arcade/Common/include/Graphical/Color.hpp
        Arcade/Common/include/ISoundPlayer.hpp
        Arcade/Common/src/Color.cpp
        Arcade/Common/src/Vector.cpp
        Arcade/Common/src/Rect.cpp
)

add_executable(
        arcade
        Arcade/Core/src/Main.cpp
        Arcade/Common/include/Math/Rect.hpp
        Arcade/Common/include/Math/Vector.hpp
        Arcade/Common/include/IGame.hpp
        Arcade/Common/include/IGraphicalLib.hpp
        Arcade/Common/include/IRenderer.hpp
        Arcade/Common/include/Graphical/ITexture.hpp
        Arcade/Common/include/Graphical/ISprite.hpp
        Arcade/Common/include/Graphical/Color.hpp
        Arcade/Common/include/ISoundPlayer.hpp
        Arcade/Common/src/Color.cpp
        Arcade/Common/src/Vector.cpp
        Arcade/Common/src/Rect.cpp
        Arcade/Core/src/Core.cpp
        Arcade/Core/include/Core.hpp
)

include_directories(Arcade/Common/include)

target_include_directories(arcade            PUBLIC Arcade/Core/include)
target_include_directories(_arcade_sfml      PUBLIC Arcade/Graphicals/SFML/include)
target_include_directories(_arcade_sdl2      PUBLIC Arcade/Graphicals/SDL2/include)
target_include_directories(_arcade_ncurses   PUBLIC Arcade/Graphicals/NCURSES/include)
target_include_directories(_arcade_nibbler   PUBLIC Arcade/Games/Nibbler/include)
target_include_directories(_arcade_centipede PUBLIC Arcade/Games/Centipede/include)
target_include_directories(_arcade_main_menu PUBLIC Arcade/Games/MainMenu/include)

target_link_libraries(arcade dl stdc++fs ncurses)