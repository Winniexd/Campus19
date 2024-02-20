
CC = cc

CFLAGS = -Wall -Wextra -Werror -g

NAME = libft.a

SRC = $(wildcard *.c)
INC = -I .

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(wildcard *_bonus.o)

ifdef BONUS
	OBJ += $(OBJ_BONUS)
endif

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs libft.a $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

bonus:
	$(MAKE) BONUS=1 all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libft.a

re: fclean all
