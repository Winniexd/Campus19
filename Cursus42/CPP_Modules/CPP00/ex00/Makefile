FLAGS= -Wall -Wextra -Werror -std=c++98

SRC= megaphone.cpp

OBJ= $(SRC:.cpp=.o)

all: $(OBJ)
	c++ $(FLAGS) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f a.out

re: fclean all