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

CXXFLAGS=	-std=c++17 -fPIC
CPPFLAGS=	-I $(CMN_DIR)/include -I $(INCLUDE_DIR) -W -Wall -Wextra -Weffc++

ifdef DEBUG
	CXXFLAGS	+=	-g3 -DDEBUG=1
endif

ifdef RAW	############################## RAW MAKEFILE ##############################

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

else		############################## PRETTY MAKEFILE ##############################

all:		$(NAME)

%.o:		%.cpp
			@printf "%12s: Compiling %s\n" $(FRIENDLY) $<
			@$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

$(NAME):	$(OBJ)
			@printf "%12s: Linking %s\n\n" $(FRIENDLY) $(NAME)
			@$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			@$(RM) $(OBJ)
			@printf "%12s: Removed object files\n" $(FRIENDLY)

fclean:		clean
			@$(RM) $(NAME)
			@printf "%12s: Removed target\n\n" $(FRIENDLY)

endif		############################## END MAKEFILE ##############################

re:			fclean all

.PHONY:		all clean fclean re
