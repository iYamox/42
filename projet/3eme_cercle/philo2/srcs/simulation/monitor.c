#include "philo.h"

static int	check_death(t_data *data)
{
	int			i;
	long long	now;
	long long	last_meal;

	i = 0;
	now = get_time_ms();
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->meal_mutex);
		last_meal = data->philos[i].last_meal_time;
		pthread_mutex_unlock(&data->meal_mutex);
		if (now - last_meal > data->time_to_die)
		{
			pthread_mutex_lock(&data->print_mutex);
			data->simulation_over = 1;
			printf("%lld %d died\n", now - data->start_time, i + 1);
			pthread_mutex_unlock(&data->print_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_all_full(t_data *data)
{
	int	full;

	if (data->must_eat == -1)
		return (0);
	pthread_mutex_lock(&data->meal_mutex);
	full = data->full_count;
	pthread_mutex_unlock(&data->meal_mutex);
	if (full >= data->nb_philos)
	{
		pthread_mutex_lock(&data->print_mutex);
		data->simulation_over = 1;
		pthread_mutex_unlock(&data->print_mutex);
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
		if (check_death(data))
			return (NULL);
		if (check_all_full(data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
