
GCC=gcc
CFLAGS=-Wall -Wextra -Werror -g
NAME=fractol

SRC=draw.c \
	fractol.c \
	hooks.c \
	init.c \
	mandelbrot.c \
	burningship.c \
	julia.c \

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -C minilibx-linux
	$(GCC) $(CFLAGS) -o $(NAME) $(OBJ) -Llibft -lft -L/usr/lib -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd
%.o: %.c
	@$(GCC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft
	@make clean -C minilibx-linux
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
