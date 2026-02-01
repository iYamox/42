/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 20:40:02 by amary             #+#    #+#             */
/*   Updated: 2026/01/13 17:18:03 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	move_player(t_game *game, int dy, int dx)
{
	int		new_x;
	int		new_y;	

	new_x = game->player.px + dx;
	new_y = game->player.py + dy;
	if (game->map.grid[new_y][new_x] == '1')
		return ;
	if ((game->map.grid[new_y][new_x] == 'E') && game->map.collectible > 0)
		return ;
	else if (game->map.grid[new_y][new_x] == 'E' && game->map.collectible == 0)
		close_game(game);
	if (game->map.grid[new_y][new_x] == 'C')
		game->map.collectible--;
	game->map.grid[game->player.py][game->player.px] = '0';
	game->map.grid[new_y][new_x] = 'P';
	game->player.px = new_x;
	game->player.py = new_y;
	render_map(game);
	game->player.count++;
	ft_putnbr(game->player.count);
	write(1, "\n", 1);
	return ;
}

void	render_map(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->map.height - 1)
	{
		w = 0;
		while (w < game->map.width - 1)
		{
			load_texture(game, 0);
			w++;
		}
		h++;
	}
	return ;
}
