/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_mid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:47:15 by amary             #+#    #+#             */
/*   Updated: 2026/01/13 16:34:25 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_load_mid(t_game *game)
{
	int		h;
	int		w;

	h = 1;
	while (h < game->map.height - 1)
	{
		w = 0;
		while (w <= game->map.width - 1)
		{
			if (w == 0)
				mlx_put_image_to_window(game->mlx, game->window,
					game->img.left_wall, w * 96, h * 96);
			if (w >= 1 && w < game->map.width - 1)
				put_img(game, h, w);
			if (w == game->map.width - 1)
				mlx_put_image_to_window(game->mlx, game->window,
					game->img.rigth_wall, w * 96, h * 96);
			w++;
		}
		h++;
	}
	return ;
}
