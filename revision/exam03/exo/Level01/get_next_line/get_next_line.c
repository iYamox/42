/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:05:51 by amary             #+#    #+#             */
/*   Updated: 2026/02/09 12:21:04 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


char *ft_strdup(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    char *dup = malloc(sizeof(char) * i + 1);
    if (!dup)
        return NULL;
    i = 0;
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return(dup);
}

char	*get_next_line(int fd)
{
	static int	pos = 0;
	static int	readed = 0;
	int			i = 0;
	static char	buffer[BUFFER_SIZE];
	char		line[70000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (pos >= readed)
		{
			readed = read(fd, buffer, BUFFER_SIZE);
			if (readed == -1)
				return (NULL);
			pos = 0;
			if (readed == 0)
				break;
		}
		line[i++] = buffer[pos++];
		if (line[i - 1] == '\n')
			break;
	}
	if (i == 0)
		return (NULL);
	line[i] = '\0';
	return (ft_strdup(line));
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;
// 	if (argc != 2)
// 		return (write(2, "Arguments error\n", 17), 1);
// 	fd = open(argv[1], O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
