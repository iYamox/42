/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 19:41:45 by amary             #+#    #+#             */
/*   Updated: 2025/12/29 12:40:00 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	*ft_fill_tab(int *tab, int size, char **argv)
{
	char	**tmp;
	int		j;
	int		k;
	int		i;

	j = 1;
	i = 0;
	while (i < size && argv[j])
	{
		k = 0;
		tmp = ft_split(argv[j++], ' ');
		while (tmp[k])
			tab[i++] = ft_atoi(tmp[k++]);
		my_free(tmp);
	}
	return (tab);
}
