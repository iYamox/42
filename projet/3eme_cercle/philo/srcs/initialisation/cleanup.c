/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:28:07 by amary             #+#    #+#             */
/*   Updated: 2026/05/07 16:28:16 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	cleanup(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->data_lock);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}
