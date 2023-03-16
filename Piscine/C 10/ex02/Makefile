
CC = cc

CFLAGS = -Wall -Wextra -Werror

INCDIR = includes
SRCDIR = src

SRC = $(wildcard $(SRCDIR)/*.c)

OBJ = $(SRC:.c=.o)

INC = -I$(INCDIR)

.PHONY: all clean fclean

all: ft_tail

ft_tail: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o ft_tail

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -g -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ft_tail

re: clean all
