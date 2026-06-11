/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:45:51 by amary             #+#    #+#             */
/*   Updated: 2026/06/11 17:41:46 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_check_death(t_table *table)
{
	int		j;
	long	time;

	j = 0;
	while (j < table->number_of_philosophers)
	{
		if (table->must_eat_count != -1
			&& ft_get_meal_count(&table->philos[j]) >= table->must_eat_count)
		{
			j++;
			continue ;
		}
		time = get_current_time() - ft_get_last_meal(&table->philos[j]);
		if (time > table->time_to_die)
		{
			ft_set_isdead(table);
			pthread_mutex_lock(&table->print_mutex);
			printf("%ld %d %s\n", get_current_time()
				- table->start_time, table->philos[j].id, "died");
			pthread_mutex_unlock(&table->print_mutex);
			return (0);
		}
		j++;
	}
	return (1);
}

void	*ft_monitor(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		if (!ft_check_death(table))
			return (NULL);
		pthread_mutex_lock(&table->full_mutex);
		if (table->must_eat_count != -1 && table->full
			== table->number_of_philosophers)
		{
			pthread_mutex_unlock(&table->full_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&table->full_mutex);
		usleep(100);
	}
	return (NULL);
}
