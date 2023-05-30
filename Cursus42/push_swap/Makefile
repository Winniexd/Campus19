CC=gcc
CFLAGS=-Wall -Wextra -Werror -g
NAME=push_swap

SRC= \
	main.c \
	ft_swap.c \
	ft_push.c \
	ft_rotate.c \
	ft_reverse_rotate.c \
	ft_fill_stack.c \
	ft_sort.c \
	push_swap_utils.c \
	check_duplicates.c \
	create_stack.c \
	ft_free_stack.c \

OBJ=$(SRC:.c=.o)
INCLUDES=push_swap.h
LIBFT=Libft/libft.a
INC=-I Libft -I .

all: $(NAME)

$(NAME): $(OBJ)
	@make -C Libft
	$(CC) $(CFLAGS) -g $(INC) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -C Libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C Libft

re: fclean all