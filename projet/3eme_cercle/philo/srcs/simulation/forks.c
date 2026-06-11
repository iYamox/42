/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:18:44 by amary             #+#    #+#             */
/*   Updated: 2026/06/11 17:44:08 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_unlock_one_fork(pthread_mutex_t *fork)
{
	if (pthread_mutex_unlock(fork) != 0)
		return (0);
	return (1);
}

int	ft_unlock_two_forks(t_philo *philo)
{
	int	ret;

	ret = 1;
	if (pthread_mutex_unlock(philo->fork_left) != 0)
		ret = 0;
	if (pthread_mutex_unlock(philo->fork_right) != 0)
		ret = 0;
	return (ret);
}

int	ft_philo_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(philo->fork_right);
	ft_printf(philo->table, philo, "has taken a fork");
	ft_printf(philo->table, philo, "has taken a fork");
	return (1);
}

int	ft_philo_even(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(philo->fork_left);
	ft_printf(philo->table, philo, "has taken a fork");
	ft_printf(philo->table, philo, "has taken a fork");
	return (1);
}

int	ft_take_forks(t_philo *philo)
{
	if (get_isdead(philo->table))
		return (0);
	if (philo->id % 2 != 0)
		return (ft_philo_odd(philo));
	else
		return (ft_philo_even(philo));
}
