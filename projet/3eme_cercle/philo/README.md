*This project has been created as part of the 42 curriculum by amary.*

## Description

This project is a deep dive into the basics of threading a process and learning how to work with concurrent programming. The goal is to solve a variation of the famous Dining Philosophers problem, simulating an environment where philosophers sit at a round table, taking turns eating, sleeping, and thinking without ever starving.

The program implements a rigorous simulation where each philosopher is represented as a separate thread. Since philosophers need two forks to eat but share them with their neighbors, the primary challenge of this project is to manage resource allocation safely using mutexes to prevent data races, conflicts, and fatal deadlocks.

## Instructions

### Compilation

The project complies with the Norm and includes a Makefile that compiles the source files using `cc` with the flags `-Wall -Wextra -Werror`.

To compile the mandatory program, navigate to the `philo/` directory and run:

```bash
make
```

This will generate the `philo` executable.

### Execution

The program takes the following command-line arguments:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: The total number of philosophers and forks at the table.
- `time_to_die` (in milliseconds): If a philosopher does not start eating within this timeframe since their last meal or the simulation start, they die.
- `time_to_eat` (in milliseconds): The duration a philosopher spends eating while holding two forks.
- `time_to_sleep` (in milliseconds): The duration a philosopher spends sleeping.
- `number_of_times_each_philosopher_must_eat` (optional): If specified, the simulation stops when all philosophers have eaten at least this many times. If omitted, the simulation only stops upon a philosopher's death.

### Clean Rules

- To remove object files: `make clean`
- To remove object files and the binary: `make fclean`
- To recompile from scratch: `make re`

## Resources

### Documentation & References

- `pthread` manual pages (`man pthread_create`, `man pthread_mutex_lock`)
- POSIX Threads programming guides and tutorials
- `en.subject.pdf` — the official 42 project guidelines

### AI Use Disclosure

In compliance with the 42 AI guidelines, AI tools (specifically Claude) were utilized during the development of this project under a strict educational framework.

- **Purpose**: Acted exclusively as a conceptual tutor to break down multi-threading, concurrency, and synchronization concepts.
- **Methodology**: A strict system prompt was enforced preventing the AI from generating any code blocks. The AI operated on a step-by-step interactive rhythm, ensuring a concept was thoroughly tested and understood before moving forward to the next technical layer.
- **Result**: All code, logic, architectural design, and debugging strategies were conceived, implemented, and verified entirely by the author.
