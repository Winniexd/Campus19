NAME=brain
FLAGS= -Wall -Wextra -Werror -std=c++98 -g

SRC= polymorphism.cpp \
main.cpp \
brain.cpp \
wrongAnimal.cpp

OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all
