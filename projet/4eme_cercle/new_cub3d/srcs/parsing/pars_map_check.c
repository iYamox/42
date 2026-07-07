/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:25:47 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/06 13:10:04 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || c == '\t' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W');
}

bool	check_map_chars(t_info *info, int i, int j)
{
	int	player;

	player = 0;
	while (info->map_final[i])
	{
		j = 0;
		while (info->map_final[i][j])
		{
			if (!is_valid_char(info->map_final[i][j]))
				return (print_error(ERROR_CHARACTER), true);
			if (info->map_final[i][j] == 'N' || info->map_final[i][j] == 'S'
				|| info->map_final[i][j] == 'E' || info->map_final[i][j] == 'W')
			{
				player++;
				info->p_x = j;
				info->p_y = i;
				info->p_dir = info->map_final[i][j];
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		return (print_error(NUMBER_PLAYER), true);
	return (false);
}
