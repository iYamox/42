/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:42:10 by amary             #+#    #+#             */
/*   Updated: 2026/06/11 17:23:49 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	join_threads(t_table *table)
{
	int	j;

	j = 0;
	while (j < table->number_of_philosophers)
	{
		if (pthread_join(table->philos[j].thread, NULL) != 0)
			continue ;
		j++;
	}
	if (pthread_join(table->monitor, NULL) != 0)
		return ;
}

int	create_threads(t_table *table)
{
	int	j;

	j = 0;
	while (j < table->number_of_philosophers)
	{
		if (pthread_create(&table->philos[j].thread, NULL, ft_routine,
				&table->philos[j]) != 0)
			return (0);
		j++;
	}
	if (pthread_create(&table->monitor, NULL, ft_monitor, table) != 0)
		return (0);
	return (1);
}
