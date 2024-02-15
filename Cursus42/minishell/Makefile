FLAGS= -Wall -Werror -Werror

SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	gcc $(FLAGS) $(OBJ)

clean:
	rm $(OBJ)

fclean: clean
	rm a.out

re: fclean all