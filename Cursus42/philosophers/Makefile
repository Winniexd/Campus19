CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = philo
SRC = 	main.c \
		init_philo.c \
		philo_utils.c
OBJ = $(SRC:.c=.o)
INC = philosophers.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re