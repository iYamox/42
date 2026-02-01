/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:30:48 by amary             #+#    #+#             */
/*   Updated: 2025/12/21 12:44:54 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_isdigit(char **argv)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	if (argv[j] == NULL)
		return (0);
	while (argv[j])
	{
		i = 0;
		if (argv[j][i] == '-' || argv[j][i] == '+')
		{
			i++;
			if (!(argv[j][i]))
				return (0);
		}
		while (argv[j][i])
		{
			if (!(argv[j][i] >= '0' && argv[j][i] <= '9'))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
