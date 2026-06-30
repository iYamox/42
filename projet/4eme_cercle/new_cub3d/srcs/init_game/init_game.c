/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:13:28 by amkhelif          #+#    #+#             */
/*   Updated: 2026/06/29 15:49:29 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

static int	free_all(void);

static int	key_hook(int keycode, t_info *info)
{
	if (keycode == ESC)
	{
		exit(0);
		printf("tu a appuyer sur echap\n");
		// free_all()
	}
	return (0);
}
void	init_game(t_info *info)
{
	init_player(info);
	info->mlx_init_struct.mlx_ptr = mlx_init();
	if (info->mlx_init_struct.mlx_ptr == NULL)
		return (print_error("Error\nMLX init failed\n"));
	info->mlx_init_struct.win_ptr = mlx_new_window(info->mlx_init_struct.mlx_ptr,
			WIDTH, HEIGHT, "Cub3D");
	if (info->mlx_init_struct.win_ptr == NULL)
		return (print_error("Error\nWindow creation failed\n"));
	mlx_hook(info->mlx_init_struct.win_ptr, CROSS, 0, free_all, info);
	// changer la fonction apres
	mlx_key_hook(info->mlx_init_struct.win_ptr, key_hook, info);
	mlx_loop_hook(info->mlx_init_struct.mlx_ptr, draw_map, info);
	mlx_loop(info->mlx_init_struct.mlx_ptr);
}

static int	free_all(void)
{
	printf("je suis dans free all \n");
	return (0);
}