cmake_minimum_required(VERSION 3.13)
project(arcade)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -Weffc++")

add_library(
        lib_arcade_main_menu
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
)

add_library(
        lib_arcade_centipede
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
)

add_library(
        lib_arcade_nibbler
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
)

add_library(
        lib_arcade_ncurses
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
)

add_library(
        lib_arcade_sdl2
        SHARED
        Arcade/Graphicals/SDL2/src/Main.cpp
        Arcade/Common/include/Math/Rect.hpp
        Arcade/Common/include/Math/Vector.hpp
        Arcade/Common/include/IGame.hpp
        Arcade/Common/include/IGraphicalLib.hpp
        Arcade/Common/include/IRenderer.hpp
        Arcade/Common/include/Graphical/ITexture.hpp
        Arcade/Common/include/Graphical/ISprite.hpp
        Arcade/Common/include/Graphical/Color.hpp
        Arcade/Common/include/ISoundPlayer.hpp
)

add_library(
        lib_arcade_sfml
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
)

include_directories(Arcade/Common)

target_include_directories(arcade               PUBLIC Arcade/Core/include)
target_include_directories(lib_arcade_sfml      PUBLIC Arcade/Graphicals/SFML/include)
target_include_directories(lib_arcade_sdl2      PUBLIC Arcade/Graphicals/SDL2/include)
target_include_directories(lib_arcade_ncurses   PUBLIC Arcade/Games/NCURSES/include)
target_include_directories(lib_arcade_nibbler   PUBLIC Arcade/Games/Nibbler/include)
target_include_directories(lib_arcade_centipede PUBLIC Arcade/Games/Centipede/include)
