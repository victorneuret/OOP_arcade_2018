##
## EPITECH PROJECT, 2018
## OOP_arcade_2018
## File description:
## Makefile
##

SHELL	=	/bin/sh
CXX		=	g++
RM		=	rm -f

SRC		=	$(shell find $(SRC_DIR) -name "*.cpp")
OBJ		=	$(SRC:.cpp=.o)
CMN_DIR	=	./Common/include

CPPFLAGS=	-I $(CMN_DIR) -I $(INCLUDE_DIR) -W -Wall -Wextra -Weffc++ -std=gnu++17

%.o:		%.cpp
			@printf "%12s: Compiling %s\n" $(FRIENDLY) $<
			@$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

all:		$(NAME)

$(NAME):	$(OBJ)
			@printf "%12s: Linking %s\n\n" $(FRIENDLY) $(NAME)
			@$(CXX) -shared -o $(NAME) $(OBJ)

clean:
			@$(RM) $(OBJ)
			@printf "%12s: Removed object files\n" $(FRIENDLY)

fclean:		clean
			@$(RM) $(NAME)
			@printf "%12s: Removed target\n\n" $(FRIENDLY)

re:			fclean all

.PHONY:		all clean fclean re
