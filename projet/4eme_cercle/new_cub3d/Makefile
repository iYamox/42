# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/23 12:33:36 by amkhelif          #+#    #+#              #
#    Updated: 2026/06/29 15:49:50 by amkhelif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3D
CC          = cc
CFLAGS		= -O3 $(INC) -std=gnu11
INCLUDES	= -I./includes -I./includes/minilibx-linux

MLX_DIR		= ./includes/minilibx-linux
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC = \
    srcs/error/error.c \
    srcs/parsing/parsing.c \
    srcs/parsing/store_info.c \
    srcs/parsing/read_file.c \
    srcs/trash/trash.c \
    srcs/utils/ft_strlen.c \
    srcs/main.c \
    libft/ft_split.c \
    libft/ft_atoi.c \
    libft/ft_strcpy.c \
    libft/ft_strjoin.c \
	libft/ft_strncmp.c \
	libft/is_digits.c \
	srcs/parsing/pars_line_colors.c \
    srcs/parsing/extract_map.c \
    srcs/parsing/pars_map.c \
    srcs/init_game/init_game.c \
    srcs/init_game/init_player.c \
    srcs/init_game/draw.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_DIR)
	$(CC) $(INCLUDES) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	@-make -C $(MLX_DIR) clean 2>/dev/null
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f vgcore.*

re: fclean all