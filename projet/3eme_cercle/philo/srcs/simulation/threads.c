/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:55:14 by amary             #+#    #+#             */
/*   Updated: 2026/05/07 16:24:46 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	start_simulation(t_data *data)
{
	pthread_t	monitor;
	int			i;

	data->start_time = get_time_in_ms();
	i = -1;
	while (++i < data->nb_philos)
	{
		data->philos[i].last_meal = data->start_time;
		if (pthread_create(&data->philos[i].thread, NULL,
				&philosopher_routine, &data->philos[i]))
			return (0);
	}
	if (pthread_create(&monitor, NULL, &monitor_routine, data))
		return (0);
	pthread_join(monitor, NULL);
	i = -1;
	while (++i < data->nb_philos)
		pthread_join(data->philos[i].thread, NULL);
	return (1);
}
