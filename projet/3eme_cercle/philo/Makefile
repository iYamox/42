NAME    = philo
CC      = cc
FLAGS   = -Wall -Werror -Wextra -Iinclude
SRCS    = srcs/main.c \
          srcs/initialisation/init.c \
          srcs/simulation/threads.c \
          srcs/simulation/routine.c \
          srcs/utils/parsing_utils.c \
          srcs/utils/status_utils.c \
          srcs/utils/time_utils.c
OBJ     = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -lpthread

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all