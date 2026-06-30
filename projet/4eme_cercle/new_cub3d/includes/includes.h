/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:26:23 by amkhelif          #+#    #+#             */
/*   Updated: 2026/06/29 17:12:20 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define CROSS 17
# define ESC 65307
# define WIDTH 320
# define HEIGHT 240
# define NUMBER_PLAYER "Error\nInvalid number of players\n"
# define ERROR_CHARACTER "Error\n character invalid\n"
# define ERROR_TEXTURE "Error\nCannot open one or more texture files\n"
# define ERROR_COLOR "Error\nInvalid color format\n"
# define ERROR_MALLOC "Error\nfunction Malloc fail\n"
# define ERROR_OPEN_FILE "Error\nfunction open\n"
# define error_number_argv "Error\nInvalid number of arguments\n"
# define ERROR_NAME_FILE "Error\nName File\n"
# define ERROR_READ "Error\nfunction read\n"

typedef struct s_mlx_init
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_lenght;
	int line_length; // Longueur d'une ligne en mémoire
	int endian;      // Sens de lecture des couleurs
}				t_mlx_init;

// struct fot store color and direction and images
typedef struct s_config
{
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*floor;
	char		*ceiling;
	int			f_rgb[3];
	int			c_rgb[3];
}				t_config;

typedef struct s_info
{
	double pos_x; // exact position of the player
	double pos_y; // exact position of the player
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	char		p_dir;
	char		**dbl_color;
	char		**map;
	char		**map_final;
	char		*file_name;
	int			p_x;
	int			p_y;
	int			fd;
	int			map_x;
	int			map_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	double		side_dist_x;
	int			step_y;
	double		side_dist_y;
	int			side;
	t_config	config;
	t_mlx_init	mlx_init_struct;
}				t_info;

// trash
void			print_double_tab(char **tab);
void			print_textures(t_info *info);

// error
void			error_read(t_info *info);

// utils
int				ft_strlen(char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strcpy(char *str);
void			free_function(char **str);
char			**ft_split(char const *s, char c);
int				ft_strncmp(const char *s1, const char *s2, int n);
char			*ft_strcpy_texture(char *str);
char			*ft_strcpy_color(char *str);
int				ft_isdigit(int c);
bool			pars_line(t_info *info);
int				ft_atoi(const char *nptr);
int				len_map(char **map, int i);

// parsing
void			print_error(char *str);
bool			check_name_file(char *str, t_info *info);
bool			read_file(t_info *info);
bool			check_all(char *str, t_info *info);
bool			extract_config(t_info *info);
bool			extract_texture(t_info *info);
bool			extract_rgb(t_info *info);
bool			extract_map(t_info *info);
bool			is_valid_char(char c);
bool			check_map_chars(t_info *info);
bool			check_map_closed(t_info *info);

// mlx init
void			init_game(t_info *info);
void			init_player_v2(t_info *info);
void			init_player_v1(t_info *info);
void			init_player(t_info *info);
int				draw_map(t_info *info);

// Étape 1 : L'initialisation des vecteurs du joueur (Position, Direction,
// Caméra).

// Étape 2 : La structure de la boucle de rendu principale (Game Loop).

// Étape 3 : Le calcul de la trajectoire des rayons (colonne par colonne).

// Étape 4 : L'algorithme DDA (le suivi du rayon dans la grille).

// Étape 5 : Le calcul de la distance et de la hauteur des murs.

// Étape 6 : Le dessin de la colonne (Plafond, Mur, Sol) dans ton image tampon.

#endif