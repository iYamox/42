/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:56:20 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/03 18:10:16 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// mais a jour la postion du joueur 
// calcul langle le champ de vision 
// lance le rayon et afiche le pixel dans limae tampom
int	draw_map(t_info *info)
{
	int		x;
	double	ray_dir_x;
	double	ray_dir_y;

	update_player_position(info);
	x = 0;
	while (x < WIDTH)
	{
		init_ray_vectors(info, x, &ray_dir_x, &ray_dir_y);
		calculate_side_distances(info, ray_dir_x, ray_dir_y);
		execute_dda(info);
		render_wall_column(info, x);
		x++;
	}
	mlx_put_image_to_window(info->mlx_init_struct.mlx_ptr,
		info->mlx_init_struct.win_ptr, info->mlx_init_struct.img_ptr, 0, 0);
	return (0);
}

// Cette fonction oriente le  laser pour la colonne de l'écran actuelle
//    note la case de départ du joueur  et calcule la distance
//    de traversée d'une case
void	init_ray_vectors(t_info *info, int x, double *ray_x, double *ray_y)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	*ray_x = info->dir_x + info->plane_x * camera_x;
	*ray_y = info->dir_y + info->plane_y * camera_x;
	info->map_x = (int)info->pos_x;
	info->map_y = (int)info->pos_y;
	if (*ray_y == 0)
		info->delta_dist_y = 1e30;
	else
		info->delta_dist_y = fabs(1.0 / *ray_y);
	if (*ray_x == 0)
		info->delta_dist_x = 1e30;
	else
		info->delta_dist_x = fabs(1.0 / *ray_x);
}

//   cette fonction  et calcule la distance initiale
//  pour atteindre lextemite de la prmier casse
void	calculate_side_distances(t_info *info, double ray_dir_x,
		double ray_dir_y)
{
	if (ray_dir_x < 0)
	{
		info->step_x = -1;
		info->side_dist_x = (info->pos_x - info->map_x) * info->delta_dist_x;
	}
	else
	{
		info->step_x = 1;
		info->side_dist_x = (info->map_x + 1.0 - info->pos_x)
			* info->delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		info->step_y = -1;
		info->side_dist_y = (info->pos_y - info->map_y) * info->delta_dist_y;
	}
	else
	{
		info->step_y = 1;
		info->side_dist_y = (info->map_y + 1.0 - info->pos_y)
			* info->delta_dist_y;
	}
}

// combien de case on doit parcourir pour toucher un mur
void	execute_dda(t_info *info)
{
	info->hit = 0;
	while (info->hit == 0)
	{
		if (info->side_dist_x < info->side_dist_y)
		{
			info->side_dist_x += info->delta_dist_x;
			info->map_x += info->step_x;
			info->side = 0;
		}
		else
		{
			info->side_dist_y += info->delta_dist_y;
			info->map_y += info->step_y;
			info->side = 1;
		}
		if (info->map_y < 0 || info->map_final[info->map_y] == NULL
			|| info->map_x < 0
			|| info->map_x >= ft_strlen(info->map_final[info->map_y])
			|| info->map_final[info->map_y][info->map_x] == ' '
			|| info->map_final[info->map_y][info->map_x] == '\t')
			break ;
		if (info->map_final[info->map_y][info->map_x] == '1')
			info->hit = 1;
	}
}
