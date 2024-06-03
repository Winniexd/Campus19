NAME=harl
FLAGS= -Wall -Wextra -Werror -std=c++98

SRC= main.cpp \
Harl.cpp

OBJ=$(SRC:.cpp=.o)

all: $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re:
	make fclean
	make all
