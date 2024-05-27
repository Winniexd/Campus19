NAME=accounts
FLAGS= -Wall -Wextra -Werror -std=c++98

SRC= tests.cpp \
Account.cpp

OBJ= $(SRC:.cpp=.o)

all: $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all