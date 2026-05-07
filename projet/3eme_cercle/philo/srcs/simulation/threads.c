/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:55:14 by amary             #+#    #+#             */
/*   Updated: 2026/05/07 16:03:52 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	start_simulation(t_data *data)
{
	int	i;

	data->start_time = get_time_in_ms();
	i = -1;
	while (++i < data->nb_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				&philosopher_routine, &data->philos[i]))
			return (0);
	}
	i = -1;
	while (++i < data->nb_philos)
		pthread_join(data->philos[i].thread, NULL);
	return (1);
}
