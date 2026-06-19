/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:12:07 by amary             #+#    #+#             */
/*   Updated: 2026/06/18 14:52:31 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_init_fork(t_table *table)
{
	table->forks = malloc(table->number_of_philosophers
			* sizeof(pthread_mutex_t));
	if (!table->forks)
		return (0);
	return (1);
}

int	ft_init_mutex(t_table *table)
{
	int	j;

	j = 0;
	while (j < table->number_of_philosophers)
	{
		if (pthread_mutex_init(&table->forks[j], NULL) != 0)
		{
			while (j > 0)
			{
				pthread_mutex_destroy(&table->forks[j - 1]);
				j--;
			}
			return (0);
		}
		j++;
	}
	return (1);
}

int	ft_init_utils_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&table->death_mutex, NULL) != 0)
		return (pthread_mutex_destroy(&table->print_mutex), 0);
	if (pthread_mutex_init(&table->last_meal_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&table->print_mutex);
		pthread_mutex_destroy(&table->death_mutex);
		return (0);
	}
	if (pthread_mutex_init(&table->full_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&table->last_meal_mutex);
		pthread_mutex_destroy(&table->death_mutex);
		pthread_mutex_destroy(&table->print_mutex);
		return (0);
	}
	return (1);
}

int	ft_init_philo(t_table *table)
{
	int	j;

	j = 0;
	table->philos = malloc(table->number_of_philosophers * sizeof(t_philo));
	if (!table->philos)
		return (0);
	while (j < table->number_of_philosophers)
	{
		table->philos[j].id = j + 1;
		table->philos[j].last_meal = 0;
		table->philos[j].fork_left = &table->forks[j];
		table->philos[j].fork_right = &table->forks[(j + 1)
			% table->number_of_philosophers];
		table->philos[j].table = table;
		j++;
	}
	return (1);
}

int	ft_init(t_table *table)
{
	table->start_time = 0;
	if (!ft_init_fork(table))
		return (0);
	if (!ft_init_mutex(table))
		return (ft_cleanup_init(table), 0);
	if (!ft_init_utils_mutex(table))
		return (ft_cleanup_init(table), 0);
	if (!ft_init_philo(table))
		return (ft_cleanup_init(table), 0);
	return (1);
}
