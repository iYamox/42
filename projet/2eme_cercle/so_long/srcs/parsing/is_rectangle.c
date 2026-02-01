/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:18:06 by amary             #+#    #+#             */
/*   Updated: 2026/01/10 21:40:20 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	is_rectangle(t_map *map)
{
	int	width;
	int	j;

	width = map->width;
	j = 0;
	while (map->grid[j])
	{
		if ((ft_strlen(map->grid[j]) - 1) != width)
		{
			if (map->grid[j + 1] != NULL)
				return (0);
			if (ft_strlen(map->grid[j]) != width)
				return (0);
		}
		j++;
	}
	return (1);
}
