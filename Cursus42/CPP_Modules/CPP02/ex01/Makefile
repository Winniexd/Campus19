NAME=fixed
FLAGS= -Wall -Wextra -Werror -std=c++98

SRC= main.cpp \
fixed.cpp \


OBJ=$(SRC:.cpp=.o)

all: $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
