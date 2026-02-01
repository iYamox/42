/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:55:29 by amary             #+#    #+#             */
/*   Updated: 2026/01/09 12:17:01 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *tmp)
{
	char	*buffer;
	int		len;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	len = 1;
	while (ft_strchr(tmp, '\n') != 1 && len != 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
			return (free(buffer), free(tmp), NULL);
		buffer[len] = '\0';
		tmp = ft_strjoin(tmp, buffer);
	}
	free(buffer);
	return (tmp);
}

char	*ft_line(char *str)
{
	int		i;
	char	*dst;
	int		j;

	if (!str[0])
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	dst = malloc (i + 2);
	if (!dst)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dst[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
	{
		dst[j] = str[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*ft_get_save(char *str)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	dst = malloc ((ft_strlen(str) - i));
	if (!dst)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
	{
		dst[j] = str[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	free(str);
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tmp = ft_read(fd, tmp);
	if (!tmp)
		return (NULL);
	line = ft_line(tmp);
	tmp = ft_get_save(tmp);
	return (line);
}

// #include <stdio.h>
// int    main(int argc, char **argv)
// {
//     int    fd;
//     char *line;

//     if (argc != 2)
//         return (write(2, "Aucun fichier n'a été renseigné\n", 34), 1);
//     fd = open(argv[1], O_RDONLY);
//     line = get_next_line(fd);
//     while (line)
//     {
//         printf("%s", line);
//         free(line);
//         line = get_next_line(fd);
//     }
//     free(line);
//     return (0);
// }