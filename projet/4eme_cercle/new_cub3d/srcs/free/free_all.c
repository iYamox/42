/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:39:02 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/06 13:14:21 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	free_all(t_info *info)
{
	if (!info)
		exit(0);
	free_textures(info);
	free_map_data(info);
	free_mlx(info);
	exit(0);
	return (0);
}

void	free_textures(t_info *info)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (info->wall_textures[i].img_ptr)
			mlx_destroy_image(info->mlx_init_struct.mlx_ptr,
				info->wall_textures[i].img_ptr);
		i++;
	}
	if (info->config.no_texture)
		free(info->config.no_texture);
	if (info->config.so_texture)
		free(info->config.so_texture);
	if (info->config.we_texture)
		free(info->config.we_texture);
	if (info->config.ea_texture)
		free(info->config.ea_texture);
	if (info->config.floor)
		free(info->config.floor);
	if (info->config.ceiling)
		free(info->config.ceiling);
}

void	free_map_data(t_info *info)
{
	if (info->dbl_color)
		free_function(info->dbl_color);
	if (info->map)
		free_function(info->map);
	if (info->map_final)
		free_function(info->map_final);
}

void	free_mlx(t_info *info)
{
	if (info->mlx_init_struct.img_ptr)
		mlx_destroy_image(info->mlx_init_struct.mlx_ptr,
			info->mlx_init_struct.img_ptr);
	if (info->mlx_init_struct.win_ptr)
		mlx_destroy_window(info->mlx_init_struct.mlx_ptr,
			info->mlx_init_struct.win_ptr);
	if (info->mlx_init_struct.mlx_ptr)
	{
		mlx_destroy_display(info->mlx_init_struct.mlx_ptr);
		free(info->mlx_init_struct.mlx_ptr);
	}
}
