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

CPPFLAGS+=	-I $(CMN_DIR)/include -I $(INCLUDE_DIR) -W -Wall -Wextra -Weffc++ -std=c++17

%.o:		%.cpp
			@printf "%12s: Compiling %s\n" $(FRIENDLY) $<
			@$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

all:		$(NAME)

$(NAME):	$(OBJ)
			@printf "%12s: Linking %s\n\n" $(FRIENDLY) $(NAME)
			@$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			@$(RM) $(OBJ)
			@printf "%12s: Removed object files\n" $(FRIENDLY)

fclean:		clean
			@$(RM) $(NAME)
			@printf "%12s: Removed target\n\n" $(FRIENDLY)

re:			fclean all

.PHONY:		all clean fclean re
