NAME=minishell
FLAGS= -Wall -Werror -Werror
SRC = 	main.c \
	builtins/pwd.c

LIBFT=libft/libft.a
INC=-Ilibft -I .

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@make -C libft
	gcc $(FLAGS) $(OBJ) $(INC) $(LIBFT) -o $(NAME)

$(NAME): $(OBJ)



clean:
	@make clean -C libft
	rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	rm -f $(NAME)

re: fclean all