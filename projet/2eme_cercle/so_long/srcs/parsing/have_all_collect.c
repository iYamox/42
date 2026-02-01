/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_all_collect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:30:01 by amary             #+#    #+#             */
/*   Updated: 2026/01/12 16:40:06 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_verif_collect(char *str, int width, int *P, int *C)
{
	int	i;

	i = 0;
	while (i <= width - 1)
	{
		if (str[i] == 'P')
			(*P)++;
		else if (str[i] == 'C')
			(*C)++;
		i++;
	}
	return ;
}

void	ft_verif_e(char *str, int width, int *E)
{
	int	i;

	i = 0;
	while (i <= width - 1)
	{
		if (str[i] == 'E')
			(*E)++;
		i++;
	}
}

int	have_all_collect(t_map *map)
{
	int	p;
	int	c;
	int	e;
	int	j;

	p = 0;
	c = 0;
	e = 0;
	j = 0;
	while (map->grid[j])
	{
		ft_verif_collect(map->grid[j], map->width, &p, &c);
		ft_verif_e(map->grid[j], map->width, &e);
		j++;
	}
	map->collectible = c;
	if (p == 1 && c >= 1 && e == 1)
		return (1);
	return (0);
}
