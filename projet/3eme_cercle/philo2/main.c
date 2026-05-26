#include "include/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (!parse_args(argc, argv, &data))
		return (1);
	if (!init_data(&data))
	{
		write(2, "Error: initialization failed\n", 29);
		return (1);
	}
	launch_simulation(&data);
	cleanup(&data);
	return (0);
}
