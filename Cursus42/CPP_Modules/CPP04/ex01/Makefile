<<<<<<< HEAD
NAME=brain
FLAGS= -Wall -Wextra -Werror -std=c++98 -g

SRC= polymorphism.cpp \
main.cpp \
brain.cpp

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
=======
NAME=polymorphism
FLAGS= -Wall -Wextra -Werror -std=c++98 -g

SRC= polymorphism.cpp \
main.cpp

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
>>>>>>> 9aa464e345c4331e245821e72bde2a1ffa3ec5ec
