NAME = libftprintf.a
CC = cc -Wall -Wextra -Werror
SRC = ft_printf_utils.c \
	  ft_printf_utils2.c \
	  ft_printf.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re