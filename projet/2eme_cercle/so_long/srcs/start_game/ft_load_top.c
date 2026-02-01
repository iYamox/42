/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:34:42 by amary             #+#    #+#             */
/*   Updated: 2026/01/10 23:15:14 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_load_top(t_game *game)
{
	int		w;

	w = 0;
	mlx_put_image_to_window(game->mlx, game->window, game->img.top_left_wall,
		w * 96, 0);
	w++;
	while (w < game->map.width - 1)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.top_wall,
			w * 96, 0);
		w++;
	}
	if (w == game->map.width - 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->img.top_rigth_wall, w * 96, 0);
	return ;
}
