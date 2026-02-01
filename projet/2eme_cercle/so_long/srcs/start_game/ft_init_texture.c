/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:43:10 by amary             #+#    #+#             */
/*   Updated: 2026/01/10 23:10:02 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_init_texture(t_game *game)
{
	int	h;
	int	w;

	game->img.top_wall = mlx_xpm_file_to_image(game->mlx,
			"Assets/Top_Wall.xpm", &h, &w);
	game->img.top_left_wall = mlx_xpm_file_to_image(game->mlx,
			"Assets/Top_Left_Wall.xpm", &h, &w);
	game->img.top_rigth_wall = mlx_xpm_file_to_image(game->mlx,
			"Assets/Top_rigth_Wall.xpm", &h, &w);
	game->img.rigth_wall = mlx_xpm_file_to_image(game->mlx,
			"Assets/Rigth_Wall.xpm", &h, &w);
	game->img.left_wall = mlx_xpm_file_to_image(game->mlx,
			"Assets/Left_Wall.xpm", &h, &w);
	ft_init_texture_v2(game);
}

void	ft_init_texture_v2(t_game *game)
{
	int	h;
	int	w;

	game->img.down_wall = mlx_xpm_file_to_image(game->mlx,
			"Assets/Down_Wall.xpm", &h, &w);
	game->img.left_down_wall = mlx_xpm_file_to_image(game->mlx,
			"Assets/Left_Down_Wall.xpm", &h, &w);
	game->img.rigth_down_wall = mlx_xpm_file_to_image(game->mlx,
			"Assets/Rigth_Down_Wall.xpm", &h, &w);
	game->img.floor = mlx_xpm_file_to_image(game->mlx,
			"Assets/Floor.xpm", &h, &w);
	game->img.player_idle = mlx_xpm_file_to_image(game->mlx,
			"Assets/Player_idle_rigth.xpm", &h, &w);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"Assets/Eglise.xpm", &h, &w);
	game->img.food = mlx_xpm_file_to_image(game->mlx,
			"Assets/Food.xpm", &h, &w);
	game->img.tree = mlx_xpm_file_to_image(game->mlx,
			"Assets/Tree.xpm", &h, &w);
	if (!game->img.top_wall)
	{
		write(2, "Error loading textures\n", 24);
		exit(1);
	}
	return ;
}
