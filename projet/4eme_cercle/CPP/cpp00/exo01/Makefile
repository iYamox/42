NAME = My_Awesome_PhoneBook
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = exo01.cpp \
        utils/init/init_phonebook.cpp \
        utils/init/init_contact.cpp \

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