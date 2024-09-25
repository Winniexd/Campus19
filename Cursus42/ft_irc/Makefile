NAME=ircserv
SRC=main.cpp

OBJ=$(SRC:.cpp=.o)
FLAGS=-Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	make clean
	rm -f $(NAME)