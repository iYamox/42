/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_correct_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:16:36 by amary             #+#    #+#             */
/*   Updated: 2026/01/10 21:41:36 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	is_correct(char *str, int width)
{
	int	i;

	i = 0;
	while (i <= width - 1)
	{
		if (str[i] == '0' || str[i] == '1')
			i++;
		else if (str[i] == 'P' || str[i] == 'C' || str[i] == 'E')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_correct_char(t_map *map)
{
	int		j;

	j = 0;
	while (map->grid[j])
	{
		if (!is_correct(map->grid[j], map->width))
			return (0);
		j++;
	}
	return (1);
}
