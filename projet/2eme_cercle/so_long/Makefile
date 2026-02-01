# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amary <amary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/06 20:30:20 by amary             #+#    #+#              #
#    Updated: 2026/01/13 17:04:20 by amary            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

MLX_PATH = minilibx-linux
MLX_LIB = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lbsd

SRC = srcs/main.c \
	srcs/utils/get_next_line.c \
	srcs/utils/get_next_line_utils.c \
	srcs/parsing/read_map.c \
	srcs/parsing/initialize_map.c \
	srcs/parsing/ft_parsing.c \
	srcs/parsing/is_rectangle.c \
	srcs/parsing/is_correct_wall.c \
	srcs/parsing/is_correct_char.c \
	srcs/parsing/have_all_collect.c \
	srcs/parsing/is_winable.c \
	srcs/parsing/flood_fill.c \
	srcs/start_game/start_game_main.c \
	srcs/start_game/load_image.c \
	srcs/start_game/ft_load_top.c \
	srcs/start_game/ft_load_down.c \
	srcs/start_game/ft_load_mid.c \
	srcs/start_game/put_img.c \
	srcs/start_game/ft_init_texture.c \
	srcs/move_player/move_player.c \
	srcs/move_player/handle_key.c \
	srcs/start_game/close_game.c \
	srcs/utils/ft_putnbr.c \
	srcs/start_game/render_loop.c \
	srcs/utils/is_ber.c \
	srcs/start_game/free_images.c \
	srcs/utils/ft_strcmp.c \
	
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
