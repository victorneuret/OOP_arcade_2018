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
        Arcade/Common/include/Graphical/ATexture.hpp
        Arcade/Common/include/Graphical/ASprite.hpp
        Arcade/Common/include/Graphical/Color.hpp
        Arcade/Games/MainMenu/src/MainMenu.cpp
        Arcade/Games/MainMenu/include/MainMenu.hpp
        Arcade/Common/src/Graphical/ATexture.cpp
        Arcade/Common/src/Graphical/ASprite.cpp
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
        Arcade/Common/include/Graphical/ATexture.hpp
        Arcade/Common/include/Graphical/ASprite.hpp
        Arcade/Common/include/Graphical/Color.hpp
        Arcade/Common/src/Graphical/Color.cpp
        Arcade/Common/src/Math/Vector.cpp
        Arcade/Common/src/Math/Rect.cpp
        Arcade/Common/src/Graphical/ATexture.cpp
        Arcade/Common/src/Graphical/ASprite.cpp
        Arcade/Games/Centipede/src/Centipede.cpp Arcade/Games/Centipede/include/Centipede.hpp Arcade/Games/Centipede/include/CentipedeTexture.hpp)

add_library(
        _arcade_nibbler
        SHARED
        Arcade/Games/Nibbler/src/Main.cpp
        Arcade/Common/include/Math/Rect.hpp
        Arcade/Common/include/Math/Vector.hpp
        Arcade/Common/include/IGame.hpp
        Arcade/Common/include/IGraphicalLib.hpp
        Arcade/Common/include/IRenderer.hpp
        Arcade/Common/include/Graphical/ATexture.hpp
        Arcade/Common/include/Graphical/ASprite.hpp
        Arcade/Common/include/Graphical/Color.hpp
        Arcade/Common/src/Graphical/Color.cpp
        Arcade/Common/src/Math/Vector.cpp
        Arcade/Common/src/Math/Rect.cpp
        Arcade/Common/src/Graphical/ATexture.cpp
        Arcade/Common/src/Graphical/ASprite.cpp
)

add_library(
        _arcade_ncurses
        SHARED
        Arcade/Common/include/Math/Rect.hpp
        Arcade/Common/include/Math/Vector.hpp
        Arcade/Common/include/IGame.hpp
        Arcade/Common/include/IGraphicalLib.hpp
        Arcade/Common/include/IRenderer.hpp
        Arcade/Common/include/Graphical/ATexture.hpp
        Arcade/Common/include/Graphical/ASprite.hpp
        Arcade/Common/include/Graphical/Color.hpp
        Arcade/Common/src/Graphical/Color.cpp
        Arcade/Common/src/Math/Vector.cpp
        Arcade/Common/src/Math/Rect.cpp
        Arcade/Graphicals/NCURSES/src/Ncurses.cpp
        Arcade/Graphicals/NCURSES/include/Ncurses.hpp
        Arcade/Graphicals/NCURSES/src/NcursesRenderer.cpp
        Arcade/Graphicals/NCURSES/include/NcursesRenderer.hpp
        Arcade/Graphicals/NCURSES/src/Main.cpp
        Arcade/Common/src/Graphical/ATexture.cpp
        Arcade/Common/src/Graphical/ASprite.cpp
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
        Arcade/Common/include/Graphical/ATexture.hpp
        Arcade/Common/include/Graphical/ASprite.hpp
        Arcade/Common/include/Graphical/Color.hpp
        Arcade/Common/src/Graphical/ATexture.cpp
        Arcade/Common/src/Graphical/ASprite.cpp
        Arcade/Common/src/Graphical/Color.cpp
        Arcade/Common/src/Math/Vector.cpp
        Arcade/Common/src/Math/Rect.cpp
        Arcade/Graphicals/SDL2/include/SDL.hpp
        Arcade/Graphicals/SDL2/include/SDLRenderer.hpp
        Arcade/Graphicals/SDL2/src/SDLRenderer.cpp
        Arcade/Graphicals/SDL2/src/Main.cpp
)

add_library(
        _arcade_sfml
        SHARED
        Arcade/Common/include/Math/Rect.hpp
        Arcade/Common/include/Math/Vector.hpp
        Arcade/Common/include/IGame.hpp
        Arcade/Common/include/IGraphicalLib.hpp
        Arcade/Common/include/IRenderer.hpp
        Arcade/Common/include/Graphical/ATexture.hpp
        Arcade/Common/include/Graphical/ASprite.hpp
        Arcade/Common/include/Graphical/Color.hpp
        Arcade/Common/src/Graphical/Color.cpp
        Arcade/Common/src/Math/Vector.cpp
        Arcade/Common/src/Math/Rect.cpp
        Arcade/Graphicals/SFML/src/SFMLRenderer.cpp
        Arcade/Graphicals/SFML/include/SFMLRenderer.hpp
        Arcade/Graphicals/SFML/src/SFML.cpp
        Arcade/Graphicals/SFML/include/SFML.hpp
        Arcade/Graphicals/SFML/src/Main.cpp
        Arcade/Common/src/Graphical/ATexture.cpp
        Arcade/Common/src/Graphical/ASprite.cpp
        Arcade/Graphicals/SFML/src/SFMLTexture.cpp
        Arcade/Graphicals/SFML/include/SFMLTexture.hpp
        Arcade/Graphicals/SFML/src/SFMLSprite.cpp
        Arcade/Graphicals/SFML/include/SFMLSprite.hpp
)

add_executable(
        arcade
        Arcade/Core/src/Main.cpp
        Arcade/Common/include/Math/Rect.hpp
        Arcade/Common/include/Math/Vector.hpp
        Arcade/Common/include/IGame.hpp
        Arcade/Common/include/IGraphicalLib.hpp
        Arcade/Common/include/IRenderer.hpp
        Arcade/Common/include/Graphical/ATexture.hpp
        Arcade/Common/include/Graphical/ASprite.hpp
        Arcade/Common/include/Graphical/Color.hpp
        Arcade/Common/src/Graphical/Color.cpp
        Arcade/Common/src/Math/Vector.cpp
        Arcade/Common/src/Math/Rect.cpp
        Arcade/Core/src/Core.cpp
        Arcade/Core/include/Core.hpp
        Arcade/Common/src/Graphical/ATexture.cpp
        Arcade/Common/src/Graphical/ASprite.cpp
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
