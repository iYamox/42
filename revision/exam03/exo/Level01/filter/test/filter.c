/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:30:09 by amary             #+#    #+#             */
/*   Updated: 2026/02/10 14:09:40 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
# define STDIN 0

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && i < len)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		len;
	int		star;
	int		readed;
	char 	str[70000];
	char	c;

	i = 0;
	if (argc == 2)
	{
		readed = read(STDIN, &c, 1);
		if (readed == 0)
			return (0);
		if (readed == -1)
			return (1);
		while (readed)
		{
			str[i++] = c;
			readed = read(STDIN, &c, 1);
			if (readed == -1)
				return (1);
		}
		str[i] = '\0';
		len = ft_strlen(argv[1]);
		if (len == 0)
			return (1);
		i = 0;
		while (str[i])
		{
			if (ft_strncmp(argv[1], &str[i], len) == 0)
			{
				star = 0;
				while (star < len)
				{
					write(1, "*", 1);
					star++;
					i++;
				}
			}
			else
				write(1, &str[i++], 1);
		}
	}
	else
		return (1);
}
