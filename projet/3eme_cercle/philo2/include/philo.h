#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define MAX_PHILOS 200

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}	t_philo;

struct s_data
{
	int				nb_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				must_eat;
	int				simulation_over;
	int				full_count;
	long long		start_time;
	pthread_mutex_t	forks[MAX_PHILOS];
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	meal_mutex;
	t_philo			philos[MAX_PHILOS];
};

/* parsing_utils.c */
int			ft_atoi_strict(const char *str, int *out);
int			parse_args(int argc, char **argv, t_data *data);

/* time_utils.c */
long long	get_time_ms(void);
void		precise_sleep(long long duration_ms, t_data *data);

/* status_utils.c */
void		print_status(t_philo *philo, const char *msg);
int			is_simulation_over(t_data *data);

/* init.c */
int			init_data(t_data *data);

/* cleanup.c */
void		cleanup(t_data *data);

/* threads.c */
int			launch_simulation(t_data *data);

/* routine.c */
void		*philo_routine(void *arg);

/* monitor.c */
void		*monitor_routine(void *arg);

#endif
