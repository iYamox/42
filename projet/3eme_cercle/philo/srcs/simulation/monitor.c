/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:19:35 by amary             #+#    #+#             */
/*   Updated: 2026/05/07 17:24:16 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	is_philo_dead(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->data->data_lock);
	time = get_time_in_ms() - philo->last_meal;
	if (time >= philo->data->time_to_die)
	{
		pthread_mutex_unlock(&philo->data->data_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->data_lock);
	return (0);
}

int	check_all_ate(t_data *data)
{
	int	i;
	int	finished_eating;

	if (data->nb_meals == -1)
		return (0);
	i = -1;
	finished_eating = 0;
	pthread_mutex_lock(&data->data_lock);
	while (++i < data->nb_philos)
	{
		if (data->philos[i].meals_count >= data->nb_meals)
			finished_eating++;
	}
	pthread_mutex_unlock(&data->data_lock);
	return (finished_eating == data->nb_philos);
}

int	check_simulation_stop(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		if (is_philo_dead(&data->philos[i]))
		{
			write_status("died", &data->philos[i]);
			pthread_mutex_lock(&data->data_lock);
			data->dead_flag = 1;
			pthread_mutex_unlock(&data->data_lock);
			return (1);
		}
	}
	if (check_all_ate(data))
	{
		pthread_mutex_lock(&data->data_lock);
		data->dead_flag = 1;
		pthread_mutex_unlock(&data->data_lock);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_simulation_stop(data))
			break ;
		usleep(1000);
	}
	return (NULL);
}
