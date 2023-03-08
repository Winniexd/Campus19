
CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes

SRC = $(addprefix $(SRCDIR)/, ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c)

OBJ = $(SRC:.c=.o)

INC = -I$(INCDIR)

.PHONY: all clean fclean re

all: libft.a

libft.a: $(OBJ)
	ar rcs libft.a $(OBJ)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean:
	rm -f libft.a

re: fclean all
