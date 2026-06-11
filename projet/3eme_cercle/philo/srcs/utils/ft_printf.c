/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:00:03 by amary             #+#    #+#             */
/*   Updated: 2026/06/11 12:00:22 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_printf(t_table *table, t_philo *philo, char *message)
{
	long	timestamp;

	pthread_mutex_lock(&table->death_mutex);
	if (!table->is_dead)
	{
		pthread_mutex_lock(&table->print_mutex);
		timestamp = get_current_time() - table->start_time;
		printf("%ld %d %s\n", timestamp, philo->id, message);
		pthread_mutex_unlock(&table->print_mutex);
	}
	pthread_mutex_unlock(&table->death_mutex);
	return ;
}
