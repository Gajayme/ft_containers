NAME		= 	containers

CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++11 -O2 -g
RM			= rm -f

#SRC			= $(wildcard *.cpp)
SRC_V			= 	vector_tests/vector_tests_main.cpp \
					vector_tests/vector_constructors_tests.cpp \
					vector_tests/vector_iter_tests.cpp \
					vector_tests/vector_reverse_iter_tests.cpp \
					vector_tests/vector_operators_tests.cpp \
					vector_tests/vector_simple_methods_tests.cpp \
					vector_tests/vector_complicated_methods_tests.cpp \

SRC_S			= stack_tests/test_stack_main.cpp

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
