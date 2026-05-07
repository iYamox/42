Execution

Run the program with the following parameters:
	./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
Example :
	./philo 5 800 200 200

Explication :
	number_of_philosophers: Number of threads/philosophers.

	time_to_die: Time (ms) after which a philosopher dies if they haven't started eating.

	time_to_eat: Time (ms) spent eating.

	time_to_sleep: Time (ms) spent sleeping.

	nb_meals (optional): Number of meals after which the simulation stops.