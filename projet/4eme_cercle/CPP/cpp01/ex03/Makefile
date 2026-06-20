NAME = UnnecessaryViolence
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = srcs/main.cpp \
		srcs/HumanA/HumanA.cpp \
		srcs/HumanB/HumanB.cpp \
		srcs/weapon/weapon.cpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re