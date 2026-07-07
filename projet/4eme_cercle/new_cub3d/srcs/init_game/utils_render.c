/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:48:47 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/06 13:08:21 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_pixel_color(int rgb[3])
{
	t_color	color;

	color.rgba.r = rgb[0];
	color.rgba.g = rgb[1];
	color.rgba.b = rgb[2];
	color.rgba.a = 0;
	return (color.raw);
}

void	put_pixel_to_image(t_info *info, int x, int y, int color)
{
	char	*pixel_ptr;
	int		memory_offset;

	memory_offset = (y * info->mlx_init_struct.line_length) + (x
			* (info->mlx_init_struct.bpp / 8));
	pixel_ptr = info->mlx_init_struct.addr + memory_offset;
	*(unsigned int *)pixel_ptr = color;
}

// calcul la hauteur du mur en fonction de la distance qui a parcouru 
void	calculate_wall_dimensions(t_info *info)
{
	if (info->side == 0)
		info->wall_dist = info->side_dist_x - info->delta_dist_x;
	else
		info->wall_dist = info->side_dist_y - info->delta_dist_y;
	if (info->wall_dist <= 0)
		info->wall_dist = 0.01;
	info->wall_height = (int)(HEIGHT / info->wall_dist);
	info->wall_top = -info->wall_height / 2 + HEIGHT / 2;
	if (info->wall_top < 0)
		info->wall_top = 0;
	info->wall_bottom = info->wall_height / 2 + HEIGHT / 2;
	if (info->wall_bottom >= HEIGHT)
		info->wall_bottom = HEIGHT - 1;
}

int	get_texture_column(t_info *info, t_texture *tex, int x)
{
	double	wall_x;
	double	camera_x;
	int		tex_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	if (info->side == 0)
		wall_x = info->pos_y + info->wall_dist * (info->dir_y + info->plane_y
				* camera_x);
	else
		wall_x = info->pos_x + info->wall_dist * (info->dir_x + info->plane_x
				* camera_x);
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if ((info->side == 0 && info->step_x > 0) || (info->side == 1
			&& info->step_y < 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}
