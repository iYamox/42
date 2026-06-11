/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:21:48 by amary             #+#    #+#             */
/*   Updated: 2026/06/11 18:43:59 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init_simulation(t_table *table)
{
	int	j;

	table->start_time = get_current_time();
	j = 0;
	while (j < table->number_of_philosophers)
	{
		table->philos[j].last_meal = table->start_time;
		j++;
	}
	return ;
}

int	one_philo(t_table *table)
{
	if (table->number_of_philosophers == 1)
	{
		ft_printf(table, &table->philos[0], "Has taken a fork");
		usleep(table->time_to_die * 1000);
		ft_printf(table, &table->philos[0], "died");
		return (1);
	}
	else
		return (0);
}

int	ft_start(t_table *table)
{
	init_simulation(table);
	if (one_philo(table))
		return (1);
	if (!create_threads(table))
		return (0);
	join_threads(table);
	return (1);
}
