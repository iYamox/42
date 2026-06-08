#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int 	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strdup(char *str);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

#endif