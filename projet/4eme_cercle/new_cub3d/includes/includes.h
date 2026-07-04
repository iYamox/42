/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:26:23 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/03 15:16:22 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define CROSS 17
# define ESC 65307
# define WIDTH 1920
# define HEIGHT 1080
# define NUMBER_PLAYER "Error\nInvalid number of players\n"
# define ERROR_CHARACTER "Error\n character invalid\n"
# define ERROR_TEXTURE "Error\nCannot open  texture files\n"
# define ERROR_COLOR "Error\nInvalid color format\n"
# define ERROR_MALLOC "Error\nMemory allocation failed\n"
# define ERROR_OPEN_FILE "Error\nCannot open or read the file\n"
# define ERROR_NUM_ARGV "Error\nInvalid number of arguments\n"
# define ERROR_NAME_FILE "Error\nInvalid file extension (must be .cub)\n"
# define ERROR_READ "Error\nFailed to read the file\n"

typedef struct s_move
{
	int					move_w;
	int					move_s;
	int					move_a;
	int					move_d;
	int					rotate_left;
	int					rotate_right;
}						t_move;

typedef struct s_mlx_init
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*addr;
	int					bpp;
	int					line_length;
	int					endian;
}						t_mlx_init;

typedef struct s_config
{
	char				*no_texture;
	char				*so_texture;
	char				*we_texture;
	char				*ea_texture;
	char				*floor;
	char				*ceiling;
	int					f_rgb[3];
	int					c_rgb[3];
}						t_config;

typedef union u_color
{
	unsigned int		raw;
	struct s_rgba
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	} rgba;
}						t_color;

typedef struct s_texture
{
	void				*img_ptr;
	char				*addr;
	int					bpp;
	int					line_length;
	int					endian;
	int					width;
	int					height;
}						t_texture;

typedef struct s_info
{
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	char				p_dir;
	char				**dbl_color;
	char				**map;
	char				**map_final;
	char				*file_name;
	int					p_x;
	int					p_y;
	int					fd;
	int					map_x;
	int					map_y;
	int					hit;
	double				delta_dist_x;
	double				delta_dist_y;
	int					step_x;
	double				side_dist_x;
	int					step_y;
	double				side_dist_y;
	int					side;
	double				wall_dist;
	int					wall_height;
	int					wall_top;
	int					wall_bottom;
	t_config			config;
	t_mlx_init			mlx_init_struct;
	t_move				move;
	t_texture			wall_textures[4];
}						t_info;

void					move_player(t_info *info);
void					print_double_tab(char **tab);
void					print_textures(t_info *info);
void					error_read(void);
void					calculate_wall_dimensions(t_info *info);
int						get_texture_column(t_info *info, t_texture *tex, int x);
void					put_pixel_to_image(t_info *info, int x, int y,
							int color);
int						ft_strlen(char *str);
char					*ft_strjoin(char *s1, char *s2);
void					rotate_player(t_info *info, double angle);
char					*ft_strcpy(char *str);
void					free_function(char **str);
char					**ft_split(char const *s, char c);
int						ft_strncmp(const char *s1, const char *s2, int n);
char					*ft_strcpy_texture(char *str);
char					*ft_strcpy_color(char *str);
int						ft_isdigit(int c);
bool					pars_line(t_info *info);
int						ft_atoi(const char *nptr);
int						len_map(char **map, int i);
bool					valid_number(int rgb[3]);
void					print_error(char *str);
bool					check_name_file(char *str, t_info *info);
bool					read_file(t_info *info);
bool					check_all(char *str, t_info *info);
bool					extract_config(t_info *info);
bool					extract_texture(t_info *info);
bool					extract_rgb(t_info *info);
bool					extract_map(t_info *info);
bool					is_valid_char(char c);
bool					check_map_chars(t_info *info, int i);
bool					check_map_closed(t_info *info);
bool					check_open_file(char *path);
void					update_player_position(t_info *info);
void					init_game(t_info *info);
void					init_player_v2(t_info *info);
void					init_player_v1(t_info *info);
void					init_player(t_info *info);
int						draw_map(t_info *info);
void					execute_dda(t_info *info);
void					calculate_side_distances(t_info *info, double ray_dir_x,
							double ray_dir_y);
void					init_ray_vectors(t_info *info, int x, double *ray_x,
							double *ray_y);
int						free_all(t_info *info);
int						handle_key_press(int keycode, t_info *info);
int						handle_key_release(int keycode, t_info *info);
void					load_textures(t_info *info);
void					render_wall_column(t_info *info, int x);
int						get_pixel_color(int rgb[3]);
int						len_dbl_tab(char **tab);
void					free_mlx(t_info *info);
void					free_map_data(t_info *info);
void					free_textures(t_info *info);

#endif /* INCLUDES_H */