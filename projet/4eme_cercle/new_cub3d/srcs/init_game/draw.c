/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:56:20 by amkhelif          #+#    #+#             */
/*   Updated: 2026/06/30 11:46:24 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

int	draw_map(t_info *info)
{
	int		x;
	double	ray_dir_x;
	double	ray_dir_y;

	x = 0;
	while (x < WIDTH)
	{
		init_ray_vectors(info, x, &ray_dir_x, &ray_dir_y);
		calculate_side_distances(info, ray_dir_x, ray_dir_y);
		execute_dda(info);
		
		// [Les calculs de distance et le dessin viendront s'ajouter ici]
		
		x++;
	}
	return (0);
}
// calcule l'angle de tir de ton pointeur laser et la distance de ses pas complets
static void	init_ray_vectors(t_info *info, int x, double *ray_x, double *ray_y)
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

// boucle principale qui calcul la distance jusqau prochain mur 
static void	calculate_side_distances(t_info *info, double ray_dir_x, double ray_dir_y)
{
	if (ray_dir_x < 0)
	{
		info->step_x = -1;
		info->side_dist_x = (info->pos_x - info->map_x) * info->delta_dist_x;
	}
	else
	{
		info->step_x = 1;
		info->side_dist_x = (info->map_x + 1.0 - info->pos_x) * info->delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		info->step_y = -1;
		info->side_dist_y = (info->pos_y - info->map_y) * info->delta_dist_y;
	}
	else
	{
		info->step_y = 1;
		info->side_dist_y = (info->map_y + 1.0 - info->pos_y) * info->delta_dist_y;
	}
}

static void	execute_dda(t_info *info)
{
	int	hit;

	hit = 0;
	while (hit == 0)
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
		if (info->map_final[info->map_y][info->map_x] == '1')
			hit = 1;
	}
}