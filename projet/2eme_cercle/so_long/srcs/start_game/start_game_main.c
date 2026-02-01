/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:05:35 by amary             #+#    #+#             */
/*   Updated: 2026/01/12 16:38:13 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map.width * 96,
			game->map.height * 96, "So_long");
	game->player.count = 0;
	load_texture(game, 1);
	mlx_hook(game->window, 17, 0, close_game, game);
	mlx_loop_hook(game->mlx, render_loop, game);
	mlx_key_hook(game->window, handle_key, game);
	mlx_loop(game->mlx);
	return ;
}
