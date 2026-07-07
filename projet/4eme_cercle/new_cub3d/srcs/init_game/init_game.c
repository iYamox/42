/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:13:28 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/06 17:23:34 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static bool	init_mlx_display(t_info *info);
static void	init_mlx_hooks(t_info *info);

// initialise les donne du joueur, init la fenetre ,
// active les interaction clacier souris ect ect
void	init_game(t_info *info)
{
	init_player(info);
	if (init_mlx_display(info))
		return ;
	init_mlx_hooks(info);
	mlx_loop(info->mlx_init_struct.mlx_ptr);
}

bool	init_mlx_display_2(t_info *info)
{
	info->mlx_init_struct.img_ptr = mlx_new_image(info->mlx_init_struct.mlx_ptr,
			WIDTH, HEIGHT);
	if (info->mlx_init_struct.img_ptr == NULL)
	{
		print_error("Error\nMLX new image failed\n");
		return (true);
	}
	info->mlx_init_struct.addr = mlx_get_data_addr(
			info->mlx_init_struct.img_ptr, &info->mlx_init_struct.bpp,
			&info->mlx_init_struct.line_length, &info->mlx_init_struct.endian);
	return (false);
}

bool	init_mlx_display(t_info *info)
{
	info->mlx_init_struct.mlx_ptr = mlx_init();
	if (info->mlx_init_struct.mlx_ptr == NULL)
	{
		print_error("Error\nMLX init failed\n");
		return (true);
	}
	load_textures(info);
	info->mlx_init_struct.win_ptr = mlx_new_window(
			info->mlx_init_struct.mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (info->mlx_init_struct.win_ptr == NULL)
	{
		print_error("Error\nWindow creation failed\n");
		return (true);
	}
	return (init_mlx_display_2(info));
}

// tout les fonction que lordinateur apelle tout le
// temps notamme la fonction qui mais a jout laffichage
void	init_mlx_hooks(t_info *info)
{
	mlx_hook(info->mlx_init_struct.win_ptr, CROSS, 0, free_all, info);
	mlx_hook(info->mlx_init_struct.win_ptr, 2, 1L << 0, handle_key_press, info);
	mlx_hook(info->mlx_init_struct.win_ptr, 3, 1L << 1, handle_key_release,
		info);
	mlx_loop_hook(info->mlx_init_struct.mlx_ptr, draw_map, info);
}
