NAME	= philo

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I include

SRCS	= main.c \
		  srcs/initialisation/init.c \
		  srcs/initialisation/cleanup.c \
		  srcs/simulation/threads.c \
		  srcs/simulation/routine.c \
		  srcs/simulation/monitor.c \
		  srcs/utils/parsing_utils.c \
		  srcs/utils/time_utils.c \
		  srcs/utils/status_utils.c

OBJS	= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
