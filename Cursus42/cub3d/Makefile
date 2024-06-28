NAME=cub3d
FLAGS=-Wall -Wextra -Werror -g
SRC=main.c utils.c init.c freeall.c \
gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C minilibx-linux
	gcc $(CFLAGS) $(OBJ) -o $(NAME) -L/usr/lib -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	@make clean -C minilibx-linux
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all
