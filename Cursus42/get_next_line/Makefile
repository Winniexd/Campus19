
CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = get_next_line

SRCDIR = srcs
INCDIR = includes

SRC = $(wildcard $(SRCDIR)/*.c)
LIB = -L$(LIBDIR)
INC = -I$(INCDIR)

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f get_next_line

re: fclean all
