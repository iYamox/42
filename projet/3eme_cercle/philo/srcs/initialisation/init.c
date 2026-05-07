/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:42:27 by amary             #+#    #+#             */
/*   Updated: 2026/05/07 16:25:27 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	init_mutexes(t_data *data)
{
	int	i;

	i = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
		return (0);
	while (++i < data->nb_philos)
		pthread_mutex_init(&data->forks[i], NULL);
	pthread_mutex_init(&data->print_lock, NULL);
	pthread_mutex_init(&data->data_lock, NULL);
	return (1);
}

static void	assign_forks(t_philo *philo)
{
	philo->left_fork = philo->id - 1;
	philo->right_fork = philo->id % philo->data->nb_philos;
}

int	init_arg(t_data *data, int argc, char **argv)
{
	data->nb_philos = (int)ft_atoi_secure(argv[1]);
	data->time_to_die = (int)ft_atoi_secure(argv[2]);
	data->time_to_eat = (int)ft_atoi_secure(argv[3]);
	data->time_to_sleep = (int)ft_atoi_secure(argv[4]);
	data->nb_meals = -1;
	if (argc == 6)
		data->nb_meals = (int)ft_atoi_secure(argv[5]);
	if (data->nb_philos < 1 || data->time_to_die < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0)
		return (0);
	if (argc == 6 && data->nb_meals <= 0)
		return (0);
	return (1);
}

int	init_all(t_data *data, int argc, char **argv)
{
	int	i;

	if (!init_arg(data, argc, argv))
		return (0);
	data->dead_flag = 0;
	if (!init_mutexes(data))
		return (0);
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->philos)
		return (0);
	i = -1;
	while (++i < data->nb_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].meals_count = 0;
		data->philos[i].last_meal = 0;
		assign_forks(&data->philos[i]);
	}
	return (1);
}
