
CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCDIR = src

SRC = $(wildcard $(SRCDIR)/*.c)

OBJ = $(SRC:.c=.o)

INC = -I$(INCDIR)

.PHONY: all clean fclean

all: ft_cat

ft_cat: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o ft_cat

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -g -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ft_cat

re: clean all
