/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:23:12 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/06 17:17:36 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static bool	check_neighbors(t_info *info, int y, int x)
{
	int	last_line;
	int	len;

	last_line = len_map(info->map_final, 0) - 1;
	if (y == 0 || y == last_line)
		return (true);
	len = ft_strlen(info->map_final[y - 1]);
	if (x >= len || info->map_final[y - 1][x] == ' ' || info->map_final[y - 1][x] == '\t')
		return (true);
	len = ft_strlen(info->map_final[y + 1]);
	if (x >= len || info->map_final[y + 1][x] == ' ' || info->map_final[y + 1][x] == '\t')
		return (true);
	if (x == 0 || info->map_final[y][x - 1] == ' ' || info->map_final[y][x - 1] == '\t')
		return (true);
	len = ft_strlen(info->map_final[y]);
	if (x + 1 >= len || info->map_final[y][x + 1] == ' ' || info->map_final[y][x + 1] == '\t')
		return (true);
	return (false);
}

static bool	check_neighbors_all(t_info *info)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (info->map_final[i])
	{
		j = 0;
		while (info->map_final[i][j])
		{
			c = info->map_final[i][j];
			if ((c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
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
	if (x < 0 || x >= len)
		return (true);
	if (map[y][x] == ' ' || map[y][x] == '\t' || map[y][x] == '\r')
		return (true);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (false);
	map[y][x] = 'V';
	if (flood_fill(map, y - 1, x, max_y) || flood_fill(map, y + 1, x, max_y) || flood_fill(map, y, x - 1, max_y) || flood_fill(map, y, x + 1, max_y))
		return (true);
	return (false);
}

bool	check_map_closed(t_info *info)
{
	int	max_y;
	int	i;
	int	j;

	max_y = len_map(info->map_final, 0);
	if (check_neighbors_all(info))
		return (print_error("Error\nMap is not closed correctly\n"), true);
	if (flood_fill(info->map_final, info->p_y, info->p_x, max_y))
		return (print_error("Error\nMap not closed \n"), true);
	i = 0;
	while (info->map_final[i])
	{
		j = 0;
		while (info->map_final[i][j])
		{
			if (info->map_final[i][j] == 'V')
				info->map_final[i][j] = '0';
			j++;
		}
		i++;
	}
	info->map_final[info->p_y][info->p_x] = info->p_dir;
	return (false);
}
