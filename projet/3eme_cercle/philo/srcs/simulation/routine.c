/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:55:12 by amary             #+#    #+#             */
/*   Updated: 2026/05/07 17:07:43 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	philo_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&data->forks[philo->right_fork]);
		write_status("has taken a fork", philo);
		pthread_mutex_lock(&data->forks[philo->left_fork]);
		write_status("has taken a fork", philo);
	}
	else
	{
		pthread_mutex_lock(&data->forks[philo->left_fork]);
		write_status("has taken a fork", philo);
		pthread_mutex_lock(&data->forks[philo->right_fork]);
		write_status("has taken a fork", philo);
	}
	write_status("is eating", philo);
	pthread_mutex_lock(&data->data_lock);
	philo->last_meal = get_time_in_ms();
	philo->meals_count++;
	pthread_mutex_unlock(&data->data_lock);
	precise_usleep(data->time_to_eat, data);
	pthread_mutex_unlock(&data->forks[philo->right_fork]);
	pthread_mutex_unlock(&data->forks[philo->left_fork]);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->nb_philos == 1)
	{
		write_status("has taken a fork", philo);
		precise_usleep(philo->data->time_to_die, philo->data);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		precise_usleep(philo->data->time_to_eat / 2, philo->data);
	while (!check_death(philo->data))
	{
		philo_eat(philo);
		write_status("is sleeping", philo);
		precise_usleep(philo->data->time_to_sleep, philo->data);
		write_status("is thinking", philo);
		if (philo->data->nb_philos % 2 != 0)
			precise_usleep(1, philo->data);
	}
	return (NULL);
}
