
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
	@make -C minilibx_opengl
	@make -C ft_printf
	@$(GCC) $(CFLAGS) -o $(NAME) $(OBJ) -Llibft -Lft_printf -lftprintf -lft -lmlx -Lminilibx_opengl -lmlx -framework OpenGL -framework AppKit
%.o: %.c
	@$(GCC) $(CFLAGS) -Ift_printf -Ilibft -Imlx -c $< -o $@

clean:
	@make clean -C libft
	@make clean -C minilibx_opengl
	@make clean -C ft_printf
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@make fclean -C ft_printf
	@rm -f $(NAME)

re: fclean all
