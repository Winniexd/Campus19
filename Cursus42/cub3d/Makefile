NAME=cub3d
FLAGS=-Wall -Wextra -Werror -g
SRC=main.c \
utils.c \
freeall.c \
init.c

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
