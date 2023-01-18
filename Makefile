NAME		= 	containers

CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++11 -O2 -g
RM			= rm -f

#SRC			= $(wildcard *.cpp)
SRC_V			= tests/test_vector.cpp
SRC_S			= tests/test_stack.cpp

#INC			= $(wildcard *.hpp)
INC_V			= vector/vector.hpp
INC_S			= stack/stack.hpp

#OBJS		= $(SRC:.cpp=.o)
OBJS_V		= $(SRC_V:.cpp=.o)
OBJS_S		= $(SRC_S:.cpp=.o)

all:
			@echo "All temporary doesnt work"
#$(NAME)

#$(NAME):	$(OBJS) $(INC) Makefile
#			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

VECTOR:	$(OBJS_V) $(INC) Makefile
			$(CXX) $(CXXFLAGS) $(OBJS_V) -o vec

STACK:	$(OBJS_S) $(INC) Makefile
			$(CXX) $(CXXFLAGS) $(OBJS_S) -o stk


%.o : %.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
			#$(RM) $(OBJS)
			$(RM) $(OBJS_V)
			$(RM) $(OBJS_S)

fclean:		clean Makefile
			#$(RM) $(NAME)
			$(RM) vec
			$(RM) stk

re: fclean all

.PHONY: all clean fclean re
