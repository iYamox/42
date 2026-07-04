/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:42:07 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/03 17:04:58 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

static void	init_single_texture(t_info *info, t_texture *tex, char *path);

// charge les textures une par une 
void	load_textures(t_info *info)
{
	init_single_texture(info, &info->wall_textures[0], info->config.no_texture);
	init_single_texture(info, &info->wall_textures[1], info->config.so_texture);
	init_single_texture(info, &info->wall_textures[2], info->config.we_texture);
	init_single_texture(info, &info->wall_textures[3], info->config.ea_texture);
}

void	init_single_texture(t_info *info, t_texture *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(info->mlx_init_struct.mlx_ptr, path,
			&tex->width, &tex->height);
	if (tex->img_ptr == NULL)
	{
		print_error("Error\nFailed to load XPM texture file\n");
		free_all(info);
	}
	tex->addr = mlx_get_data_addr(tex->img_ptr, &tex->bpp, &tex->line_length,
			&tex->endian);
}
