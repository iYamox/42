/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:29:07 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/03 18:02:01 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

// centre le joueur dans sa case 
void	init_player(t_info *info)
{
	info->pos_x = (double)info->p_x + 0.5;
	info->pos_y = (double)info->p_y + 0.5;
	if (info->p_dir == 'N' || info->p_dir == 'S')
		init_player_v1(info);
	else if (info->p_dir == 'E' || info->p_dir == 'W')
		init_player_v2(info);
}

// initalise angle de vue du joeur esr ca direction de marche 
void	init_player_v1(t_info *info)
{
	if (info->p_dir == 'N')
	{
		info->dir_x = 0.0;
		info->dir_y = -1.0;
		info->plane_x = 0.66;
		info->plane_y = 0.0;
	}
	else if (info->p_dir == 'S')
	{
		info->dir_x = 0.0;
		info->dir_y = 1.0;
		info->plane_x = -0.66;
		info->plane_y = 0.0;
	}
}

// initalise angle de vue du joeur esr ca direction de marche 
void	init_player_v2(t_info *info)
{
	if (info->p_dir == 'E')
	{
		info->dir_x = 1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = 0.66;
	}
	else if (info->p_dir == 'W')
	{
		info->dir_x = -1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = -0.66;
	}
}
