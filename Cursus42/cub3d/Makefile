NAME=cub3d
FLAGS=-Wall -Wextra -Werror -g
SRC= main.c init.c struct_bzero.c hooks.c \
parse/parse.c \
utils/clean_exit.c \
utils/ft_split.c \
utils/ft_strlcpy.c \
utils/utils.c \
utils/ft_atoi.c \
gnl/get_next_line.c \
gnl/get_next_line_utils.c


OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C minilibx-linux
	gcc $(FLAGS) $(OBJ) -o $(NAME) -L/usr/lib -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd

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
