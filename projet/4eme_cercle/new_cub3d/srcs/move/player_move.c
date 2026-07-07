/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:01:16 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/03 13:00:52 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// Vérifie si la position est valide
static int	is_walkable(t_info *info, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || info->map_final[map_y] == NULL)
		return (0);
	if (map_x < 0 || map_x >= ft_strlen(info->map_final[map_y]))
		return (0);
	if (info->map_final[map_y][map_x] == '1'
		|| info->map_final[map_y][map_x] == ' '
		|| info->map_final[map_y][map_x] == '\t')
		return (0);
	return (1);
}

static void	get_move_vector(t_info *info, double *mov_x, double *mov_y)
{
	if (info->move.move_w)
	{
		*mov_x += info->dir_x;
		*mov_y += info->dir_y;
	}
	if (info->move.move_s)
	{
		*mov_x -= info->dir_x;
		*mov_y -= info->dir_y;
	}
	if (info->move.move_d)
	{
		*mov_x += info->plane_x;
		*mov_y += info->plane_y;
	}
	if (info->move.move_a)
	{
		*mov_x -= info->plane_x;
		*mov_y -= info->plane_y;
	}
}

static void	apply_move(t_info *info, double mov_x, double mov_y)
{
	double	mar_x;
	double	mar_y;

	if (mov_x < 0)
		mar_x = -0.2;
	else
		mar_x = 0.2;
	if (mov_y < 0)
		mar_y = -0.2;
	else
		mar_y = 0.2;
	if (is_walkable(info, info->pos_x + mov_x + mar_x, info->pos_y))
		info->pos_x += mov_x;
	if (is_walkable(info, info->pos_x, info->pos_y + mov_y + mar_y))
		info->pos_y += mov_y;
}

void	move_player(t_info *info)
{
	double	mov_x;
	double	mov_y;
	double	speed;

	speed = 0.01;
	mov_x = 0;
	mov_y = 0;
	get_move_vector(info, &mov_x, &mov_y);
	mov_x *= speed;
	mov_y *= speed;
	apply_move(info, mov_x, mov_y);
}
