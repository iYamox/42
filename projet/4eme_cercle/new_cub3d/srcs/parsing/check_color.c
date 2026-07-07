/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:15:09 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/03 13:18:16 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	valid_number(int rgb[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (true);
		i++;
	}
	return (false);
}

int	len_dbl_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
		return (1);
	return (0);
}
