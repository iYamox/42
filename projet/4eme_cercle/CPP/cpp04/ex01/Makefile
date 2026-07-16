NAME = Animal
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = srcs/main.cpp \
		srcs/animal.cpp \
		srcs/dog.cpp \
		srcs/cat.cpp \
		srcs/wrongAnimal.cpp \
		srcs/wrongCat.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -Iincludes/

%.o: %.cpp
	$(CC) $(FLAGS) -Iincludes/ -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
