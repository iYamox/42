/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:46:22 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/03 18:20:06 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// Sélectionne la texture (NO, SO, EA, WE) à appliquer sur le mur impacté
static t_texture	*get_wall_texture(t_info *info)
{
	if (info->side == 0 && info->step_x < 0)
		return (&info->wall_textures[2]);
	if (info->side == 0 && info->step_x > 0)
		return (&info->wall_textures[3]);
	if (info->side == 1 && info->step_y < 0)
		return (&info->wall_textures[0]);
	return (&info->wall_textures[1]);
}

// afiche pixels par pixel sr limage tampom
static void	draw_column_pixels(t_info *info, int x, t_texture *tex, int tex_x)
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;

	step = 1.0 * tex->height / info->wall_height;
	tex_pos = (info->wall_top - HEIGHT / 2 + info->wall_height / 2) * step;
	y = 0;
	while (y < HEIGHT)
	{
		if (y < info->wall_top)
			put_pixel_to_image(info, x, y, get_pixel_color(info->config.c_rgb));
		else if (y >= info->wall_top && y <= info->wall_bottom)
		{
			tex_y = (int)tex_pos & (tex->height - 1);
			tex_pos += step;
			put_pixel_to_image(info, x, y, *(unsigned int *)(tex->addr + (tex_y
						* tex->line_length + tex_x * (tex->bpp / 8))));
		}
		else
			put_pixel_to_image(info, x, y, get_pixel_color(info->config.f_rgb));
		y++;
	}
}

void	render_wall_column(t_info *info, int x)
{
	t_texture	*tex;
	int			tex_x;

	calculate_wall_dimensions(info);
	tex = get_wall_texture(info);
	tex_x = get_texture_column(info, tex, x);
	draw_column_pixels(info, x, tex, tex_x);
}
