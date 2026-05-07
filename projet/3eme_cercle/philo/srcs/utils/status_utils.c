/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:01:14 by amary             #+#    #+#             */
/*   Updated: 2026/05/07 16:01:17 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	check_death(t_data *data)
{
	int	stopped;

	pthread_mutex_lock(&data->data_lock);
	stopped = data->dead_flag;
	pthread_mutex_unlock(&data->data_lock);
	return (stopped);
}

void	write_status(char *str, t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->data->print_lock);
	time = get_time_in_ms() - philo->data->start_time;
	if (!check_death(philo->data))
		printf("%lld %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->print_lock);
}

void	precise_usleep(long long time, t_data *data)
{
	long long	start;

	start = get_time_in_ms();
	while (!check_death(data))
	{
		if (get_time_in_ms() - start >= time)
			break ;
		usleep(500);
	}
}
