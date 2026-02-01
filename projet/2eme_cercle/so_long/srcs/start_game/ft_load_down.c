/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:45:13 by amary             #+#    #+#             */
/*   Updated: 2026/01/10 23:15:55 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_load_down(t_game *game)
{
	int	w;
	int	h;

	h = game->map.height - 1;
	w = 0;
	mlx_put_image_to_window(game->mlx, game->window, game->img.left_down_wall,
		w * 96, h * 96);
	w++;
	while (w < game->map.width - 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.down_wall,
			w * 96, h * 96);
		w++;
	}
	if (w == game->map.width - 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->img.rigth_down_wall, w * 96, h * 96);
	return ;
}
