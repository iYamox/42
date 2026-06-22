/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:36:21 by amary             #+#    #+#             */
/*   Updated: 2026/06/11 17:41:37 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_set_isdead(t_table *table)
{
	pthread_mutex_lock(&table->death_mutex);
	table->is_dead = 1;
	pthread_mutex_unlock(&table->death_mutex);
}

int	get_isdead(t_table *table)
{
	int	value;

	pthread_mutex_lock(&table->death_mutex);
	value = table->is_dead;
	pthread_mutex_unlock(&table->death_mutex);
	if (value)
		return (1);
	pthread_mutex_lock(&table->full_mutex);
	if (table->must_eat_count != -1
		&& table->full == table->number_of_philosophers)
	{
		pthread_mutex_unlock(&table->full_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table->full_mutex);
	return (0);
}
