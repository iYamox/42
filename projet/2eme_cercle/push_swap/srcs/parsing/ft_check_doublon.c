/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_doublon.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:30:52 by amary             #+#    #+#             */
/*   Updated: 2025/12/21 19:43:19 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_doublon(int *tab, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i] == tab[j] && (i != j))
				return (0);
			j++;
		}
	}
	return (1);
}

int	ft_check_doublon(char **argv)
{
	int		*tab;
	int		size;

	size = ft_arg_len(argv);
	tab = malloc(size * sizeof(int));
	if (!tab)
		return (0);
	tab = ft_fill_tab(tab, size, argv);
	if (is_doublon(tab, size) == 0)
		return (free(tab), 0);
	else
		return (free(tab), 1);
}
