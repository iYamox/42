/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:14:50 by amary             #+#    #+#             */
/*   Updated: 2026/01/10 23:28:38 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_player(game, -1, 0);
	else if (keycode == KEY_S)
		move_player(game, 1, 0);
	else if (keycode == KEY_A)
		move_player(game, 0, -1);
	else if (keycode == KEY_D)
		move_player(game, 0, 1);
	else if (keycode == KEY_ESC)
		close_game(game);
	return (0);
}
