#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_rules
{
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	pthread_mutex_t	*fork;
}					t_rules;

typedef struct s_philo
{
	pthread_t	p_ID;
	int			left_fork_index;
	int			right_fork_index;
}				t_philo;

#endif