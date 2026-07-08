NAME = ClapTrap
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = srcs/main.cpp \
		srcs/ClapTrap.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
