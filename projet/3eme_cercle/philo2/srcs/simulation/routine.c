#include "philo.h"

static void	take_forks_single(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	precise_sleep(philo->data->time_to_die + 1, philo->data);
	pthread_mutex_unlock(philo->left_fork);
}

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal_time = get_time_ms();
	pthread_mutex_unlock(&philo->data->meal_mutex);
}

static void	eat(t_philo *philo)
{
	print_status(philo, "is eating");
	precise_sleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->meals_eaten++;
	if (philo->data->must_eat != -1
		&& philo->meals_eaten == philo->data->must_eat)
		philo->data->full_count++;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->nb_philos == 1)
	{
		take_forks_single(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		precise_sleep(philo->data->time_to_eat, philo->data);
	while (!is_simulation_over(philo->data))
	{
		take_forks(philo);
		if (is_simulation_over(philo->data))
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			break ;
		}
		eat(philo);
		if (is_simulation_over(philo->data))
			break ;
		print_status(philo, "is sleeping");
		precise_sleep(philo->data->time_to_sleep, philo->data);
		if (is_simulation_over(philo->data))
			break ;
		print_status(philo, "is thinking");
	}
	return (NULL);
}
