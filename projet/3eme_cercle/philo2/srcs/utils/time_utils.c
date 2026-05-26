#include "philo.h"

long long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	precise_sleep(long long duration_ms, t_data *data)
{
	long long	start;
	long long	elapsed;

	start = get_time_ms();
	while (1)
	{
		if (is_simulation_over(data))
			return ;
		elapsed = get_time_ms() - start;
		if (elapsed >= duration_ms)
			return ;
		if (duration_ms - elapsed > 2)
			usleep(500);
		else
			usleep(100);
	}
}
