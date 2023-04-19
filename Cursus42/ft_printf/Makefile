
CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a

SRCDIR=srcs
INCDIR=includes

SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(SRC:.c=.o)
INC=-I $(INCDIR)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c -g -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all