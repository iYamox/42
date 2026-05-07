/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:19:19 by amary             #+#    #+#             */
/*   Updated: 2026/05/07 16:23:45 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ================ Includes ================ */

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

/* ================ Structure ================ */

typedef struct s_data	t_data;

typedef struct s_philo
{
	int			id;
	long long	last_meal;
	int			meals_count;
	int			left_fork;
	int			right_fork;
	pthread_t	thread;
	t_data		*data;
}				t_philo;

struct s_data
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	long long		start_time;
	int				dead_flag;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	data_lock;
	t_philo			*philos;
};

/* ================ Utils ================ */

long		ft_atoi_secure(char *str);
long long	get_time_in_ms(void);

/* ================ Initialisation ================ */

void		init_arg(t_data *data, int argc, char **argv);
int			init_all(t_data *data, int argc, char **argv);

/* ================ Simulation ================ */

int			start_simulation(t_data *data);
void		*philosopher_routine(void *arg);
void		philo_eat(t_philo *philo);
void		precise_usleep(long long time, t_data *data);
void		write_status(char *str, t_philo *philo);
int			is_philo_dead(t_philo *philo);
void		*monitor_routine(void *arg);
int			check_simulation_stop(t_data *data);
int			check_all_ate(t_data *data);

#endif