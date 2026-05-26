#include "philo.h"

static int	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->meal_mutex, NULL) != 0)
		return (0);
	return (1);
}

static void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = 0;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->nb_philos];
		i++;
	}
}

int	init_data(t_data *data)
{
	data->simulation_over = 0;
	data->full_count = 0;
	if (!init_mutexes(data))
		return (0);
	init_philos(data);
	return (1);
}
