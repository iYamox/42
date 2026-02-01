/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_correct_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:55:00 by amary             #+#    #+#             */
/*   Updated: 2026/01/10 21:51:45 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	for_first_and_last(char *str, int width)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (i < width)
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_correct_wall(t_map *map)
{
	int	j;
	int	width;

	j = 0;
	width = map->width;
	if (for_first_and_last(map->grid[j], width) == 0)
		return (0);
	j++;
	while (map->grid[j + 1])
	{
		if (!(map->grid[j][0] == '1' && map->grid[j][width - 1] == '1'))
			return (0);
		j++;
	}
	if (for_first_and_last(map->grid[j], width) == 0)
		return (0);
	return (1);
}
