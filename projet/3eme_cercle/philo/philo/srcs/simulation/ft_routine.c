/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:47:39 by amary             #+#    #+#             */
/*   Updated: 2026/06/11 17:43:50 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_eat(t_philo *philo)
{
	if (!ft_take_forks(philo))
		return (0);
	ft_set_last_meal(philo);
	ft_printf(philo->table, philo, "Is eating");
	philo->status = EATING;
	ft_wait(philo);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	if (!ft_check_meal_count(philo))
		return (0);
	return (1);
}

int	ft_sleep(t_philo *philo)
{
	if (get_isdead(philo->table))
		return (0);
	ft_printf(philo->table, philo, "Is sleeping");
	philo->status = SLEEPING;
	ft_wait(philo);
	if (get_isdead(philo->table))
		return (0);
	return (1);
}

int	ft_think(t_philo *philo)
{
	if (get_isdead(philo->table))
		return (0);
	ft_printf(philo->table, philo, "Is thinking");
	philo->status = THINKING;
	ft_wait(philo);
	if (get_isdead(philo->table))
		return (0);
	return (1);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(philo->table->time_to_eat * 1000);
	while (1)
	{
		if (!ft_eat(philo))
			return (NULL);
		if (!ft_sleep(philo))
			return (NULL);
		if (!ft_think(philo))
			return (NULL);
	}
	return (NULL);
}
