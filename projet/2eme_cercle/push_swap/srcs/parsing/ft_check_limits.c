/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_limits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:30:50 by amary             #+#    #+#             */
/*   Updated: 2025/12/20 19:08:12 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_check_limits(char **arg)
{
	long	nb;
	int		j;

	j = 0;
	while (arg[j])
	{
		if (ft_strlen(arg[j]) > 11)
			return (0);
		nb = ft_atoi(arg[j]);
		if (nb > INT_MAX)
			return (0);
		if (nb < INT_MIN)
			return (0);
		j++;
	}
	return (1);
}
