/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_trier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:57:53 by amary             #+#    #+#             */
/*   Updated: 2025/12/23 15:41:14 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_trier(int *tab, int size)
{
	int	i;
	int	min;

	i = 0;
	min = tab[i];
	while (++i < size)
	{
		if (min < tab[i])
			min = tab[i];
		else
			return (0);
	}
	return (1);
}
