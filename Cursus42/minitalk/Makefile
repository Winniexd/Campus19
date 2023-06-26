
CLIENT=client
SERVER=server

CC=gcc
CFLAGS=-Wall -Wextra -Werror
CLIENT_SRC=client.c
SERVER_SRC=server.c
CLIENT_OBJ=$(CLIENT_SRC:.c=.o)
SERVER_OBJ=$(SERVER_SRC:.c=.o)
INC=ft_printf/libftprintf.a

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	make -C ft_printf
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(INC) -o $(CLIENT)

$(SERVER): $(SERVER_OBJ)
	make -C ft_printf
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(INC) -o $(SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	$(MAKE) -C ft_printf fclean

re: fclean all

