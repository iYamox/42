#include "philo.h"

static void	join_all(t_data *data, pthread_t monitor, int nb)
{
	int	i;

	pthread_join(monitor, NULL);
	i = 0;
	while (i < nb)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

int	launch_simulation(t_data *data)
{
	int			i;
	pthread_t	monitor;

	data->start_time = get_time_ms();
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->meal_mutex);
		data->philos[i].last_meal_time = data->start_time;
		pthread_mutex_unlock(&data->meal_mutex);
		if (pthread_create(&data->philos[i].thread, NULL,
				philo_routine, &data->philos[i]) != 0)
		{
			pthread_mutex_lock(&data->print_mutex);
			data->simulation_over = 1;
			pthread_mutex_unlock(&data->print_mutex);
			while (i > 0)
			{
				i--;
				pthread_join(data->philos[i].thread, NULL);
			}
			return (0);
		}
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_routine, data) != 0)
	{
		pthread_mutex_lock(&data->print_mutex);
		data->simulation_over = 1;
		pthread_mutex_unlock(&data->print_mutex);
		i = 0;
		while (i < data->nb_philos)
		{
			pthread_join(data->philos[i].thread, NULL);
			i++;
		}
		return (0);
	}
	join_all(data, monitor, data->nb_philos);
	return (1);
}
