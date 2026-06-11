/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:36:28 by amary             #+#    #+#             */
/*   Updated: 2026/06/11 11:35:36 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	argc_is_5(t_table *table, char **argv)
{
	long	result;
	int		j;

	j = 1;
	while (j < 5)
	{
		if (!ft_isdigit(argv[j]))
			return (0);
		result = ft_atol(argv[j]);
		if (result == 0 || result > INT_MAX || result < 0)
			return (0);
		if (j == 1)
			table->number_of_philosophers = result;
		else if (j == 2)
			table->time_to_die = result;
		else if (j == 3)
			table->time_to_eat = result;
		else if (j == 4)
			table->time_to_sleep = result;
		j++;
	}
	return (1);
}

int	argc_is_6(t_table *table, int argc, char **argv)
{
	long	result;

	if (argc == 6)
	{
		if (!ft_isdigit(argv[5]))
			return (0);
		result = ft_atol(argv[5]);
		if (result == 0 || result > INT_MAX || result < 0)
			return (0);
		table->must_eat_count = result;
	}
	else
		table->must_eat_count = -1;
	return (1);
}

int	ft_parsing(int argc, char **argv, t_table *table)
{
	if (argc < 5 || argc > 6)
		return (0);
	if (!argc_is_5(table, argv))
		return (0);
	if (!argc_is_6(table, argc, argv))
		return (0);
	return (1);
}
