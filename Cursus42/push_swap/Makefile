CC=gcc
CFLAGS=-Wall -Wextra -Werror -g
NAME=push_swap

SRC= \
	main.c \
	ps_list_init.c \
	ps_list_utils.c \
	ps_sort.c \
	ps_utils.c \
	ps_sort_small.c \
	ps_swap.c \
	ps_push.c \
	ps_rotate.c \
	ps_reverse_rotate.c \
	ps_assign_pos.c \

OBJ=$(SRC:.c=.o)
INCLUDES=push_swap.h
LIBFT=libft/libft.a
INC=-I libft -I .

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all