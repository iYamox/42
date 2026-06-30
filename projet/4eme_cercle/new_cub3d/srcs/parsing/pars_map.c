/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:23:12 by amkhelif          #+#    #+#             */
/*   Updated: 2026/06/25 15:00:18 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

 bool	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == '\t' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	check_map_chars(t_info *info)
{
	int i;
	int j;
	int player;

	i = 0;
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


static bool	check_first_last_line(char *line)
{
	int	i;
	int	has_wall;

	i = 0;
	has_wall = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ' && line[i] != '\t')
			return (true);
		if (line[i] == '1')
			has_wall = 1;
		i++;
	}
	if (!has_wall)
		return (true);
	return (false);
}

static bool	check_middle_line(char *line)
{
	int	i;
	int	len;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '1')
		return (true);
	len = ft_strlen(line) - 1;
	while (len > i && (line[len] == ' ' || line[len] == '\t'))
		len--;
	if (line[len] != '1')
		return (true);
	return (false);
}

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

bool	check_map_closed(t_info *info)
{
	int	i;
	int	last;

	last = len_map(info->map_final, 0) - 1;
	if (check_first_last_line(info->map_final[0]))
		return (print_error("Error\nMap not closed \n"), true);
	if (check_first_last_line(info->map_final[last]))
		return (print_error("Error\nMap not closed \n"), true);
	i = 1;
	while (i < last)
	{
		if (check_middle_line(info->map_final[i]))
			return (print_error("Error\nMap not closed\n"), true);
		i++;
	}
	if (check_neighbors_all(info))
		return (print_error("Error\nMap not closed \n"), true);
	return (false);
} 