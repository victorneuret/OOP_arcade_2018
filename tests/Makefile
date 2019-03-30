##
## EPITECH PROJECT, 2018
## OOP_arcade_2018
## File description:
## Makefile
##

SHELL	=	/bin/sh
CXX		=	g++
RM		=	rm -f

NAME	=	tests_run

SRC		=	$(shell find . -name "*.cpp" 2> /dev/null) 			\
			$(shell find ../Arcade -name "*.cpp" -not -name "Main.cpp" 2> /dev/null)
OBJ		=	$(SRC:.cpp=.o)

CXXFLAGS=	-std=c++17 -fPIC

LDFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system		\
			-lSDL2 -lSDL2_ttf -lSDL2_image					\
			-lncurses										\
			-ldl -lstdc++fs									\
			-lcriterion --coverage

CPPFLAGS=	$(shell find ../ -name "include" -type d | sed 's/\.\.\// -I\.\.\//g')	\
			-W -Wall -Wextra -Weffc++												\
			--coverage

%.o:	%.cpp
		@printf "%12s: Compiling %s\n" $(NAME) $<
		@$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

all:	$(OBJ)
		@$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		@find .. \( -name '*.gcda' -o -name '*.gcno' -o -name '*.gcov' \) -delete
		@$(RM) $(OBJ)

cov_clean:
		@find .. \( -name '*.gcda' -o -name '*.gcno' -o -name '*.gcov' \) -delete

fclean:
		@find .. \( -name '*.gcda' -o -name '*.gcno' -o -name '*.gcov' \) -delete
		@$(RM) $(OBJ)
		@$(RM) $(NAME)

.PHONY:		all clean fcleann cov_clean
