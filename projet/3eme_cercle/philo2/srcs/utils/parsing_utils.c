#include "philo.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi_strict(const char *str, int *out)
{
	long	result;
	int		i;

	i = 0;
	result = 0;
	if (!str || !str[0])
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (0);
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		if (result > INT_MAX)
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	*out = (int)result;
	return (1);
}

int	parse_args(int argc, char **argv, t_data *data)
{
	int	tmp;

	if (argc < 5 || argc > 6)
	{
		write(2, "Usage: philo nb_philos time_to_die time_to_eat", 46);
		write(2, " time_to_sleep [nb_must_eat]\n", 29);
		return (0);
	}
	if (!ft_atoi_strict(argv[1], &tmp) || tmp < 1 || tmp > MAX_PHILOS)
		return (write(2, "Error: invalid number of philosophers\n", 38), 0);
	data->nb_philos = tmp;
	if (!ft_atoi_strict(argv[2], &tmp) || tmp < 1)
		return (write(2, "Error: invalid time_to_die\n", 27), 0);
	data->time_to_die = (long long)tmp;
	if (!ft_atoi_strict(argv[3], &tmp) || tmp < 1)
		return (write(2, "Error: invalid time_to_eat\n", 27), 0);
	data->time_to_eat = (long long)tmp;
	if (!ft_atoi_strict(argv[4], &tmp) || tmp < 1)
		return (write(2, "Error: invalid time_to_sleep\n", 29), 0);
	data->time_to_sleep = (long long)tmp;
	data->must_eat = -1;
	if (argc == 6)
	{
		if (!ft_atoi_strict(argv[5], &tmp) || tmp < 1)
			return (write(2, "Error: invalid must_eat\n", 24), 0);
		data->must_eat = tmp;
	}
	return (1);
}
