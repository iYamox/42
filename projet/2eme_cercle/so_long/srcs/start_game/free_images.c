/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 00:04:37 by amary             #+#    #+#             */
/*   Updated: 2026/01/11 00:05:33 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.top_wall);
	mlx_destroy_image(game->mlx, game->img.top_left_wall);
	mlx_destroy_image(game->mlx, game->img.top_rigth_wall);
	mlx_destroy_image(game->mlx, game->img.rigth_wall);
	mlx_destroy_image(game->mlx, game->img.left_wall);
	mlx_destroy_image(game->mlx, game->img.down_wall);
	mlx_destroy_image(game->mlx, game->img.left_down_wall);
	mlx_destroy_image(game->mlx, game->img.rigth_down_wall);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.player_idle);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.food);
	mlx_destroy_image(game->mlx, game->img.tree);
}
