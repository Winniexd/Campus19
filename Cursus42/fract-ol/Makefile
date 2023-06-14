
GCC=gcc
CFLAGS=-Wall -Wextra -Werror -g
NAME=fractol

SRC=draw.c \
	fractol.c \
	hooks.c \
	init.c \
	mandelbrot.c \

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -C minilibx-linux
	@make -C ft_printf
	@$(GCC) $(CFLAGS) -o $(NAME) $(OBJ) -Llibft -lft -Lft_printf -L/usr/lib -lftprintf -Lminilibx-linux -lmlx -lXext -lX11 -lm

%.o: %.c
	@$(GCC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft
	@make clean -C minilibx-linux
	@make clean -C ft_printf
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@make fclean -C ft_printf
	@rm -f $(NAME)

re: fclean all
