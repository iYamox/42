/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:55:01 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/03 12:57:07 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	update_player_position(t_info *info)
{
	move_player(info);
	if (info->move.rotate_right)
		rotate_player(info, 0.01);
	if (info->move.rotate_left)
		rotate_player(info, -0.01);
}

void	rotate_player(t_info *info, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dir_x;
	info->dir_x = info->dir_x * cos(angle) - info->dir_y * sin(angle);
	info->dir_y = old_dir_x * sin(angle) + info->dir_y * cos(angle);
	old_plane_x = info->plane_x;
	info->plane_x = info->plane_x * cos(angle) - info->plane_y * sin(angle);
	info->plane_y = old_plane_x * sin(angle) + info->plane_y * cos(angle);
}
