/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_winable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:49:27 by amary             #+#    #+#             */
/*   Updated: 2026/01/13 17:10:04 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	**cpy_grid(t_map *map)
{
	char	**cpy;
	int		j;

	j = 0;
	cpy = malloc((map->height + 1) * sizeof(char *));
	if (!cpy)
		return (NULL);
	cpy[map->height] = NULL;
	while (j < map->height)
	{
		cpy[j] = ft_strdup(map->grid[j]);
		if (!cpy[j])
			return (free_grid(cpy, map->height), NULL);
		j++;
	}
	return (cpy);
}

void	ft_find_player(char **grid, int heigth, int *px, int *py)
{
	int	x;
	int	y;

	y = 0;
	while (y < heigth)
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'P')
			{
				*py = y;
				*px = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	check_winable(char **grid, int heigth)
{
	int	y;
	int	x;

	y = 0;
	while (y <= heigth - 1)
	{
		x = 0;
		while (grid[y][x])
		{
			if (!(grid[y][x] == '1' || grid[y][x] == 'V'))
				if (grid[y][x] != '\n')
					if (grid[y][x] != '0')
						return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	free_grid(char **grid, int heigth)
{
	int	j;

	j = 0;
	while (j < heigth)
		free(grid[j++]);
	free(grid);
}

int	is_winable(t_map *map)
{
	char	**cpy;
	int		px;
	int		py;
	int		result;

	cpy = cpy_grid(map);
	if (!cpy)
		return (0);
	ft_find_player(cpy, map->height, &px, &py);
	flood_fill(cpy, px, py);
	result = check_winable(cpy, map->height);
	if (result)
	{
		free_grid(cpy, map->height);
		cpy = cpy_grid(map);
		if (!cpy)
			return (0);
		flood_fill2(cpy, px, py);
		result = check_winable2(cpy, map->height);
	}
	free_grid(cpy, map->height);
	return (result);
}
