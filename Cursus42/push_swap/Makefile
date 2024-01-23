CC=gcc
CFLAGS=-Wall -Wextra -Werror -g
NAME=push_swap
CHECK=checker

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
	ps_radix_sort.c \

CHECKER_SRC= \
	checker.c \
	ps_list_init.c \
	ps_list_utils.c \
	ps_swap.c \
	ps_push.c \
	ps_rotate.c \
	ps_reverse_rotate.c \
	ps_utils.c \
	ps_assign_pos.c \

GNL_SRC= \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \

OBJ=$(SRC:.c=.o)
OBJ_CHECKER=$(CHECKER_SRC:.c=.o)
OBJ_GNL=$(GNL_SRC:.c=.o)

INCLUDES=push_swap.h \
	get_next_line/get_next_line.h \

LIBFT=libft/libft.a
INC=-I libft -I .

all: $(NAME) $(CHECK)

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(CHECK): $(OBJ_CHECKER) $(OBJ_GNL)
	@make -C libft
	$(CC) $(CFLAGS) $(INC) $(OBJ_CHECKER) $(OBJ_GNL) $(LIBFT) -o $(CHECK)

clean:
	@rm -f $(OBJ)
	@make clean -C libft
	@rm -f $(OBJ_CHECKER)
	@rm -f $(OBJ_GNL)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(CHECK)
	@make fclean -C libft

re: fclean all