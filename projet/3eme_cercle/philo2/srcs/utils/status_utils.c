#include "philo.h"

void	print_status(t_philo *philo, const char *msg)
{
	long long	ts;

	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->simulation_over || msg[0] == 'd')
	{
		ts = get_time_ms() - philo->data->start_time;
		printf("%lld %d %s\n", ts, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}

int	is_simulation_over(t_data *data)
{
	int	over;

	pthread_mutex_lock(&data->print_mutex);
	over = data->simulation_over;
	pthread_mutex_unlock(&data->print_mutex);
	return (over);
}
