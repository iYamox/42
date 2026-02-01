/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:08:35 by amary             #+#    #+#             */
/*   Updated: 2026/01/15 15:24:12 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	flood_fill(char **grid, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (grid[y][x] == '1' || grid[y][x] == 'V')
		return ;
	grid[y][x] = 'V';
	flood_fill(grid, x + 1, y);
	flood_fill(grid, x - 1, y);
	flood_fill(grid, x, y + 1);
	flood_fill(grid, x, y - 1);
	return ;
}

void	flood_fill2(char **grid, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (grid[y][x] == '1' || grid[y][x] == 'V' || grid[y][x] == 'E')
		return ;
	grid[y][x] = 'V';
	flood_fill2(grid, x + 1, y);
	flood_fill2(grid, x - 1, y);
	flood_fill2(grid, x, y + 1);
	flood_fill2(grid, x, y - 1);
	return ;
}

int	check_winable2(char **grid, int heigth)
{
	int	y;
	int	x;

	y = 0;
	while (y <= heigth - 1)
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
