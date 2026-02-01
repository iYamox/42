/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 20:27:29 by amary             #+#    #+#             */
/*   Updated: 2026/01/13 16:45:18 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../srcs/utils/get_next_line.h"
# include "../minilibx-linux/mlx.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
	int		collectible;
}			t_map;

typedef struct s_img
{
	void	*top_wall;
	void	*top_left_wall;
	void	*top_rigth_wall;
	void	*rigth_wall;
	void	*left_wall;
	void	*down_wall;
	void	*left_down_wall;
	void	*rigth_down_wall;
	void	*floor;
	void	*player_idle;
	void	*exit;
	void	*food;
	void	*tree;
}			t_img;

typedef struct s_player
{
	int	px;
	int	py;
	int	count;
}		t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map		map;
	t_img		img;
	t_player	player;
}				t_game;

t_map	read_map(char *str);
char	*get_next_line(int fd);
void	initialize_map(char *str, t_map *map);
int		ft_parsing(t_map *map);
int		is_rectangle(t_map *map);
int		is_correct_wall(t_map *map);
int		for_first_and_last(char *str, int width);
int		is_correct_char(t_map *map);
int		is_correct(char *str, int width);
int		have_all_collect(t_map *map);
void	ft_verif_collect(char *str, int width, int *P, int *C);
void	ft_verif_E(char *str, int width, int *E);
int		is_winable(t_map *map);
char	**cpy_grid(t_map *map);
void	ft_find_player(char **grid, int heigth, int *px, int *py);
int		check_winable(char **grid, int heigth);
void	free_grid(char **grid, int heigth);
void	flood_fill(char **grid, int y, int x);
void	free_map(t_map map);
void	start_game(t_game *game);
void	ft_init_texture(t_game *game);
void	ft_init_texture_v2(t_game *game);
void	load_texture(t_game *game, int init);
void	ft_load_top(t_game *game);
void	ft_load_mid(t_game *game);
void	put_img(t_game *game, int h, int w);
void	ft_load_down(t_game *game);
void	move_player(t_game *game, int dy, int dx);
void	render_map(t_game *game);
int		handle_key(int keycode, t_game *game);
int		close_game(t_game *game);
void	change_direction(t_game *game, int px);
void	ft_putnbr(int nb);
int		render_loop(t_game *game);
void	free_images(t_game *game);
int		is_ber(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	flood_fill2(char **grid, int x, int y);
int		check_winable2(char **grid, int heigth);

#endif