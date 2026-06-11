/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:09:53 by amary             #+#    #+#             */
/*   Updated: 2026/06/11 11:36:32 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_cleanup(t_table *table)
{
	if (!table)
		return ;
	if (table && table->forks)
		free(table->forks);
	if (table && table->philos)
		free(table->philos);
	if (table)
		free(table);
	return ;
}

void	ft_cleanup_init(t_table *table)
{
	int	j;

	j = 0;
	while (j < table->number_of_philosophers)
	{
		pthread_mutex_destroy(&table->forks[j]);
		j++;
	}
	if (table->forks)
		free(table->forks);
	if (table->philos)
		free(table->philos);
}
