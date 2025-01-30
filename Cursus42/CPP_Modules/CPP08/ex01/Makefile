NAME=span
FLAGS=-Wall -Wextra -Werror -std=c++98
SRC=main.cpp \
span.cpp

OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all