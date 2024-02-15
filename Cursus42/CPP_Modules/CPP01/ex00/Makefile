FLAGS= -Wall -Wextra -Werror -std=c++98

SRC= main.cpp \
	NewZombie.cpp \
	RandomChump.cpp \
	Zombie.cpp

OBJ=$(SRC:.cpp=.o)

all:
	c++ $(FLAGS) $(OBJ)

clean:
	rm $(OBJ)

fclean: clean
	rm a.out

re: fclean all
