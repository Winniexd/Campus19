# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jepatern <jepatern@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 16:04:05 by jepatern          #+#    #+#              #
#    Updated: 2024/05/22 12:55:47 by jepatern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
C_ARG := -Wall -Wextra -Werror

# Source files
SRCS := ft_atoi.c \
	ft_isprint.c \
	ft_putchar_fd.c \
	ft_striteri.c \
	ft_strnstr.c \
	ft_bzero.c \
	ft_itoa.c \
	ft_putendl_fd.c \
	ft_strjoin.c \
	ft_strrchr.c \
	ft_calloc.c \
	ft_memchr.c \
	ft_putnbr_fd.c \
	ft_strlcat.c \
	ft_strtrim.c \
	ft_isalnum.c \
	ft_memcmp.c \
	ft_putstr_fd.c \
	ft_strlcpy.c \
	ft_substr.c \
	ft_isalpha.c \
	ft_memcpy.c \
	ft_split.c \
	ft_strlen.c \
	ft_tolower.c \
	ft_isascii.c \
	ft_memmove.c \
	ft_strchr.c \
	ft_strmapi.c \
	ft_toupper.c \
	ft_isdigit.c \
	ft_memset.c \
	ft_strdup.c \
	ft_strncmp.c \
	ft_ope.c \
	ft_printf.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_get_next_line.c \
	ft_get_next_line_utils.c \
	ft_putnbr.c \
	ft_there_is_c.c \
	ft_strcmp.c \
	ft_strdiff.c \
	ft_handle_memory.c \

# Object files
OBJS := $(patsubst %.c, objects/%.o, $(SRCS))

# Targets
all: libft.a

debug: FLAGS += -DMODE_DEBUG=1 -g3 -fstack-protector
debug: fclean $(NAME)
	@echo "\nvalgrind --tool=memcheck --suppressions=readline-leaks-ignore.txt --show-leak-kinds=all --leak-check=full --track-origins=yes --undef-value-errors=yes -q -v ./$(NAME)"

objects/%.o: %.c
	@mkdir -p objects
	@printf "libft : LIBFT library is compiling ...\r"
	@cc $(C_ARG) -c $< -o $@

libft.a: $(OBJS)
	@ar rc libft.a $(OBJS)
	@echo "\nlibft : libft.a created successfully."

clean:
	@rm -rf objects

fclean: clean
	@rm -f libft.a

re: fclean all

.PHONY: all clean fclean re

