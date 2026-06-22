NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/main.c \
		srcs/parsing/ft_parsing.c \
		srcs/parsing/ft_parsing_utils.c \
		srcs/cleanup/clean.c \
		srcs/initialisation/ft_init.c \
		srcs/simulation/start.c \
		srcs/simulation/time.c \
		srcs/utils/ft_printf.c \
		srcs/simulation/thread.c \
		srcs/simulation/ft_routine.c \
		srcs/simulation/forks.c \
		srcs/simulation/meals.c \
		srcs/simulation/is_dead.c \
		srcs/simulation/ft_monitor.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 