
SRC = ft_display_file.c
OBJ = ft_display_file.o

.PHONY: all clean fclean

all: ft_display_file

ft_display_file: $(OBJ)
	cc -Wall -Wextra -Werror $(OBJ) -o ft_display_file

ft_display_file.o: $(SRC)
	cc -Wall -Wextra -Werror -c $(SRC)

clean:
	rm -f ft_display_file.o ft_display_file

fclean: clean all
