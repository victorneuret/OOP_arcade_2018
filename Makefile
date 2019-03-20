##
## EPITECH PROJECT, 2018
## OOP_arcade_2018
## File description:
## Makefile
##

SHELL	=	/bin/sh
CXX		=	g++
RM		=	rm -f
FRIENDLY=	"UnitTests"

SUB_MAKE=	make --no-print-directory -C Arcade

CORE	=	$(SUB_MAKE) SRC_DIR=./Core/src							\
						INCLUDE_DIR=./Core/include					\
						LDFLAGS="-ldl -lstdc++fs"					\
						NAME=../arcade								\
						FRIENDLY="Core"

MENU	=	$(SUB_MAKE) SRC_DIR=./Games/MainMenu/src				\
						INCLUDE_DIR=./Games/MainMenu/include 		\
						LDFLAGS="-shared"							\
						NAME=../games/lib_arcade_main_menu.so		\
						FRIENDLY="MainMenu"

CENTIP	=	$(SUB_MAKE) SRC_DIR=./Games/Centipede/src				\
						INCLUDE_DIR=./Games/Centipede/include		\
						LDFLAGS="-shared"							\
						NAME=../games/lib_arcade_centipede.so		\
						FRIENDLY="Centipede"

NIBBLER	=	$(SUB_MAKE) SRC_DIR=./Games/Nibbler/src					\
						INCLUDE_DIR=./Games/Nibbler/include 		\
						LDFLAGS="-shared"							\
						NAME=../games/lib_arcade_nibbler.so 		\
						FRIENDLY="Nibbler"

NCURSES	=	$(SUB_MAKE) SRC_DIR=./Graphicals/NCURSES/src			\
						INCLUDE_DIR=./Graphicals/NCURSES/include	\
						LDFLAGS="-lncurses -shared"					\
						NAME=../lib/lib_arcade_ncurses.so 			\
						FRIENDLY="NCURSES"

SDL2	=	$(SUB_MAKE) SRC_DIR=./Graphicals/SDL2/src				\
						INCLUDE_DIR=./Graphicals/SDL2/include 		\
						LDFLAGS="-lSDL -shared"						\
						NAME=../lib/lib_arcade_sdl2.so 				\
						FRIENDLY="SDL2"

SFML	=	$(SUB_MAKE) SRC_DIR=./Graphicals/SFML/src				\
						INCLUDE_DIR=./Graphicals/SFML/include 		\
						LDFLAGS="-lsfml-graphics -lsfml-window -lsfml-system -shared" \
						NAME=../lib/lib_arcade_sfml.so 				\
						FRIENDLY="SFML"

CMN_DIR	=	./Arcade/Common
CMN_SRC	=	$(shell find $(CMN_DIR)/src -name "*.cpp")
CMN_OBJ	=	$(CMN_SRC:.cpp=.o)

SRC_UNIT=	$(shell find tests -name "*.cpp" 2> /dev/null) 			\
			$(shell find Arcade -name "*.cpp" -not -name "Main.cpp" 2> /dev/null)
OBJ_UNIT=	$(SRC_UNIT:.cpp=.o)

CXXFLAGS=	-std=c++17 -fPIC
CPPFLAGS=	-Iinclude -I $(CMN_DIR)/include -W -Wall -Wextra -Weffc++

ifeq ($(DEBUG), 1)
	CXXFLAGS	+=	-g3 -DDEBUG=1
endif

all:		core games graphicals

common:		FRIENDLY="Common"
common:		$(CMN_OBJ)

core:		common
			@$(CORE) all

games:		common
			@$(MENU) all
			@$(CENTIP) all
			@$(NIBBLER) all

graphicals:	common
			@$(NCURSES) all
			@$(SDL2) all
			@$(SFML) all

clean:
			@$(CORE) clean
			@$(MENU) clean
			@$(CENTIP) clean
			@$(NIBBLER) clean
			@$(NCURSES) clean
			@$(SDL2) clean
			@$(SFML) clean
			@$(RM) $(OBJ_UNIT)
			@printf "%12s: Removed object files\n" $(FRIENDLY)

fclean:
			@$(CORE) fclean
			@$(MENU) fclean
			@$(CENTIP) fclean
			@$(NIBBLER) fclean
			@$(NCURSES) fclean
			@$(SDL2) fclean
			@$(SFML) fclean
			@$(RM) $(OBJ_UNIT) $(CMN_OBJ)
			@$(RM) tests_run
			@printf "%12s: Removed object files\n" $(FRIENDLY)
			@printf "%12s: Removed unit tests target\n\n" $(FRIENDLY)

re:			fclean all

%.o:		%.cpp
			@printf "%12s: Compiling %s\n" $(FRIENDLY) $<
			@$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

tests_run:	LDFLAGS		+=	-lsfml-graphics -lsfml-window -lsfml-system		\
							-lSDL2 -lncurses								\
							-lcriterion --coverage
tests_run:	CPPFLAGS	+=	--coverage
tests_run:	fclean $(OBJ_UNIT)
			@printf "%12s: Linking %s\n" $(FRIENDLY)
			@$(CXX) -o tests_run $(OBJ_UNIT) $(LDFLAGS)
			@./tests_run --verbose -j1

cov_gen:
			@gcovr -s --exclude tests

cov_clean:
			find . \( -name '*.gcda' -o -name '*.gcno' -o -name '*.gcov' \) -delete

bigclean:	fclean cov_clean

.PHONY:		all clean fclean re cov_gen cov_clean tests_run bigclean core games graphicals
