/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:35:09 by amary             #+#    #+#             */
/*   Updated: 2026/06/11 17:23:01 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ==================== Includes ==================== */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

/* ==================== MACRO ==================== */

# define EATING				1
# define SLEEPING			2
# define THINKING			3
# define FORK				4

/* ==================== Struct ==================== */

typedef struct s_table	t_table;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	pthread_mutex_t		*fork_left;
	pthread_mutex_t		*fork_right;
	long				last_meal;
	t_table				*table;
	int					meal_count;
	int					status;
}						t_philo;

typedef struct s_table
{
	int					number_of_philosophers;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					must_eat_count;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		death_mutex;
	pthread_mutex_t		last_meal_mutex;
	pthread_t			monitor;
	int					is_dead;
	long				start_time;
	t_philo				*philos;
	int					full;
	pthread_mutex_t		full_mutex; // Pour le cas ou argv = 6
}						t_table;

/* ==================== Fonction ==================== */

int		ft_parsing(int argc, char **argv, t_table *table);
int		argc_is_5(t_table *table, char **argv);
int		argc_is_6(t_table *table, int argc, char **argv);
int		ft_strlen(char *str);
int		ft_isdigit(char *str);
long	ft_atol(char *nptr);
void	ft_cleanup(t_table *table);
void	ft_cleanup_init(t_table *table);
int		ft_init(t_table *table);
int		ft_init_fork(t_table *table);
int		ft_init_utils_mutex(t_table *table);
int		ft_init_philo(t_table *table);
int		ft_start(t_table *table);
void	init_simulation(t_table *table);
long	get_current_time(void);
void	ft_wait(t_philo *philo);
int		one_philo(t_table *table);
void	ft_printf(t_table *table, t_philo *philo, char *message);
int		create_threads(t_table *table);
void	*ft_routine(void *arg);
int		ft_think(t_philo *philo);
int		ft_sleep(t_philo *philo);
int		ft_eat(t_philo *philo);
int		ft_take_forks(t_philo *philo);
int		ft_philo_even(t_philo *philo);
int		ft_philo_odd(t_philo *philo);
int		ft_unlock_two_forks(t_philo *philo);
int		ft_unlock_one_fork(pthread_mutex_t *fork);
int		ft_check_meal_count(t_philo *philo);
long	ft_get_meal_count(t_philo *philo);
void	ft_set_last_meal(t_philo *philo);
long	ft_get_last_meal(t_philo *philo);
int		get_isdead(t_table *table);
void	ft_set_isdead(t_table *table);
void	*ft_monitor(void *arg);
int		ft_check_death(t_table *table);
void	join_threads(t_table *table);

#endif