NAME=zombie
FLAGS= -Wall -Wextra -Werror -std=c++98

SRC= main.cpp \
	NewZombie.cpp \
	RandomChump.cpp \
	Zombie.cpp

OBJ=$(SRC:.cpp=.o)

all: $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
