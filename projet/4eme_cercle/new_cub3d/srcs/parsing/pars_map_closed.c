/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_closed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:26:05 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/06 13:13:55 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static bool	check_neighbors(t_info *info, int y, int x)
{
	int	len;

	if (y == 0 || y == (len_map(info->map_final, 0) - 1))
		return (true);
	len = ft_strlen(info->map_final[y - 1]);
	if (x >= len || info->map_final[y - 1][x] == ' ' || info->map_final[y
		- 1][x] == '\t')
		return (true);
	len = ft_strlen(info->map_final[y + 1]);
	if (x >= len || info->map_final[y + 1][x] == ' ' || info->map_final[y
		+ 1][x] == '\t')
		return (true);
	if (x == 0 || info->map_final[y][x - 1] == ' ' || info->map_final[y][x
		- 1] == '\t')
		return (true);
	len = ft_strlen(info->map_final[y]);
	if (x + 1 >= len || info->map_final[y][x + 1] == ' ' || info->map_final[y][x
		+ 1] == '\t')
		return (true);
	return (false);
}

static bool	is_player_or_floor(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static bool	check_neighbors_all(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map_final[i])
	{
		j = 0;
		while (info->map_final[i][j])
		{
			if (is_player_or_floor(info->map_final[i][j])
				&& check_neighbors(info, i, j))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static bool	flood_fill(char **map, int y, int x, int max_y)
{
	int	len;

	if (y < 0 || y >= max_y)
		return (true);
	len = ft_strlen(map[y]);
	if (x < 0 || x >= len || map[y][x] == ' ' || map[y][x] == '\t')
		return (true);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (false);
	map[y][x] = 'V';
	return (flood_fill(map, y - 1, x, max_y) || flood_fill(map, y + 1, x, max_y)
		|| flood_fill(map, y, x - 1, max_y) || flood_fill(map, y, x + 1,
			max_y));
}
