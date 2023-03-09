
SRC = ft_cat.c
OBJ = ft_cat.o

.PHONY: all clean fclean

all: ft_cat

ft_cat: $(OBJ)
	cc -Wall -Wextra -Werror $(OBJ) -o ft_cat

ft_cat.o: $(SRC)
	cc -Wall -Wextra -Werror -c $(SRC)

clean:
	rm -f ft_cat.o ft_cat

fclean: clean all
