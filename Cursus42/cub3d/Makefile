# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matias <matias@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 08:52:37 by jepatern          #+#    #+#              #
#    Updated: 2024/11/14 17:16:39 by matias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
FLAGS = -O1 -funroll-loops -g -Wall -Wextra -Werror
MINILIBXDIR = includes_library/minilibx-linux
LIBFT = includes_library/ft_libft/libft.a
SOURCES = sources
OBJECTS = objects

SRC_CUB3D = \
	main.c \
    parser/init.c \
    parser/core_parser.c \
    parser/struct_bzero.c \
	parser/fill_colors.c \
    parser/fill_directions.c \
	parser/fill_map.c \
	parser/parse_xpm.c \
	parser/check_map.c \
	exec/rendering.c \
	exec/ray_casting.c \
	exec/hooks.c \
	utils/clean_exit.c \
    utils/utils.c \
    utils/get_path.c \
    utils/display_config.c

SRC = $(addprefix $(SOURCES)/, $(SRC_CUB3D))
OBJ = $(patsubst $(SOURCES)/%.c, $(OBJECTS)/%.o, $(SRC))

OS_NAME := $(shell uname -s)

ifeq ($(OS_NAME), Darwin)
	LDFLAGS += -Lminilibx-opengl -lmlx -framework OpenGL -framework AppKit
	MINILIBXDIR = minilibx-opengl
	SRC += sources/utils/macos.c
endif

ifeq ($(OS_NAME), Linux)
	LDFLAGS += -L$(MINILIBXDIR) -lmlx -lXext -lX11 -lbsd
endif

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MINILIBXDIR)
	@make -C $(dir $(LIBFT))
	gcc $(FLAGS) -DBONUS=$(BONUS) $(OBJ) -o $(NAME) $(LDFLAGS) $(LIBFT) -lm -I includes_library

$(OBJECTS)/%.o: $(SOURCES)/%.c
	@mkdir -p $(@D)
	gcc $(FLAGS) -DBONUS=$(BONUS) -I includes_library -c $< -o $@

bonus:
	make all BONUS=1

clean:
	@make clean -C $(MINILIBXDIR)
	@make clean -C $(dir $(LIBFT))
	rm -rf $(OBJECTS)

fclean: clean
	@make fclean -C $(dir $(LIBFT))
	rm -rf $(NAME)

re: fclean all
