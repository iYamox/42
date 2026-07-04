# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/23 12:33:36 by amkhelif          #+#    #+#              #
#    Updated: 2026/07/03 15:35:54 by amkhelif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3D
CC          = cc -g3
CFLAGS		= -O3 $(INC) -std=gnu11
INCLUDES	= -I./includes -I./includes/minilibx-linux

MLX_DIR		= ./includes/minilibx-linux
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC = \
    libft/ft_strlen.c \
    libft/ft_split.c \
    libft/ft_atoi.c \
    libft/ft_strcpy.c \
    libft/ft_strjoin.c \
	libft/ft_strncmp.c \
	libft/is_digits.c \
    srcs/error/error.c \
    srcs/parsing/parsing.c \
    srcs/parsing/store_info.c \
    srcs/parsing/read_file.c \
	srcs/parsing/pars_line_colors.c \
    srcs/parsing/pars_map.c \
    srcs/parsing/extract_map.c \
    srcs/parsing/check_color.c \
    srcs/parsing/pars_map_check.c \
    srcs/parsing/pars_map_closed.c \
    srcs/init_game/init_texture.c \
    srcs/init_game/utils_render.c \
    srcs/move/player_move_utils.c \
    srcs/free/free_all.c \
    srcs/main.c \
    srcs/init_game/init_game.c \
    srcs/init_game/init_player.c \
    srcs/init_game/render.c \
    srcs/init_game/draw.c \
    srcs/move/move.c \
    srcs/move/player_move.c

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