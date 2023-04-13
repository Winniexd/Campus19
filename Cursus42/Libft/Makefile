
CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCDIR = srcs
INCDIR = includes

SRC = $(wildcard $(SRCDIR)/*.c)
INC = -I$(INCDIR)

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs libft.a $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libft.a

re: fclean all
