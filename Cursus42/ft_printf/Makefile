CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
INCDIR = includes
INC = -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
