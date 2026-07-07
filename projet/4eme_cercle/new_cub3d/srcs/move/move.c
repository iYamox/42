/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:55:33 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/01 10:55:43 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// S'active dès qu'on enfonce une touche : passe l'interrupteur à 1
int	handle_key_press(int keycode, t_info *info)
{
	if (keycode == ESC)
		free_all(info);
	if (keycode == KEY_W)
		info->move.move_w = 1;
	if (keycode == KEY_S)
		info->move.move_s = 1;
	if (keycode == KEY_A)
		info->move.move_a = 1;
	if (keycode == KEY_D)
		info->move.move_d = 1;
	if (keycode == KEY_LEFT)
		info->move.rotate_left = 1;
	if (keycode == KEY_RIGHT)
		info->move.rotate_right = 1;
	return (0);
}

// S'active dès qu'on relâche une touche : passe l'interrupteur à 0
int	handle_key_release(int keycode, t_info *info)
{
	if (keycode == KEY_W)
		info->move.move_w = 0;
	if (keycode == KEY_S)
		info->move.move_s = 0;
	if (keycode == KEY_A)
		info->move.move_a = 0;
	if (keycode == KEY_D)
		info->move.move_d = 0;
	if (keycode == KEY_LEFT)
		info->move.rotate_left = 0;
	if (keycode == KEY_RIGHT)
		info->move.rotate_right = 0;
	return (0);
}
