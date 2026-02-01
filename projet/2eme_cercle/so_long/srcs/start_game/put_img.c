/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:54:09 by amary             #+#    #+#             */
/*   Updated: 2026/01/10 23:16:40 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	put_img(t_game *game, int h, int w)
{
	if (game->map.grid[h][w] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->img.floor,
			w * 96, h * 96);
	if (game->map.grid[h][w] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->img.food,
			w * 96, h * 96);
	if (game->map.grid[h][w] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.player_idle,
			w * 96, h * 96);
		game->player.px = w;
		game->player.py = h;
	}
	if (game->map.grid[h][w] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->img.tree,
			w * 96, h * 96);
	if (game->map.grid[h][w] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->img.exit,
			w * 96, h * 96);
	return ;
}
