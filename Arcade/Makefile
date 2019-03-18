##
## EPITECH PROJECT, 2018
## OOP_arcade_2018
## File description:
## Makefile
##

SHELL	=	/bin/sh
CXX		=	g++
RM		=	rm -f

CMN_DIR	=	./Common
SRC		=	$(shell find $(SRC_DIR) -name "*.cpp") $(shell find $(CMN_DIR)/src -name "*.cpp")
OBJ		=	$(SRC:.cpp=.o)

CXXFLAGS=	-std=gnu++17 -fPIC
CPPFLAGS=	-I $(CMN_DIR)/include -I $(INCLUDE_DIR) -W -Wall -Wextra -Weffc++

%.o:		%.cpp
			@printf "%12s: Compiling %s\n" $(FRIENDLY) $<
			@$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

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
