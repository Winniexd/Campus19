NAME=zombiehorde
FLAGS= -Wall -Wextra -Werror -std=c++98

SRC= main.cpp \
	Zombie.cpp \
	ZombieHorde.cpp

OBJ=$(SRC:.cpp=.o)

all: $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
