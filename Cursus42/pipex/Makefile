
NAME=pipex

SRC=pipex.c \
	pipex_utils.c \
	main.c \
	command_init.c \

OBJ=$(SRC:.c=.o)
CFLAGS= -Wall -Werror -Wextra -g
LIBFT=Libft/libft.a
INCLUDES= -I Libft -I .

all: $(NAME)

$(NAME): $(OBJ)
	@make -C Libft
	gcc $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -C Libft

fclean: clean
	rm -f $(NAME)
	@make fclean -C Libft

re: fclean all

.PHONY: all clean fclean re