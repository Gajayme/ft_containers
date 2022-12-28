NAME		= 	containers

CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -O2 -g
RM			= rm -f

#SRC			= $(wildcard *.cpp)
SRC			= test_vector.cpp

INC			= $(wildcard *.hpp)

OBJS		= $(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INC) Makefile
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
