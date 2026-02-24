/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:20:21 by amary             #+#    #+#             */
/*   Updated: 2026/02/24 13:32:55 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i = 0;
	
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	int	i;
	char *dst;
	
	dst = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = -1;
	while (str[++i])
		dst[i] = str[i];
	dst[i] = '\0';
	return (dst);
}

char *get_next_line(int fd)
{
	int			i = 0;
	static int	pos = 0;
	static int	readed = 0;
	static char buffer[BUFFER_SIZE];
	char		line[70000];

	while (1)
	{
		if (pos >= readed)
		{
			readed = read(fd, buffer, BUFFER_SIZE);
			if (readed == -1)
				return (NULL);
			pos = 0;
			if (readed == 0)
				break ;
		}
		line[i++] = buffer[pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	if (i == 0)
		return (NULL);
	line[i] = '\0';
	return (ft_strdup(line));
}

int main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (1);
		line = get_next_line(fd);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
	}
	return (0);
}
