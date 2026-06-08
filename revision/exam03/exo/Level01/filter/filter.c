/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:50:20 by amary             #+#    #+#             */
/*   Updated: 2026/06/08 15:02:18 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STDIN 0
#define STDOUT 1
#define STDERROR 2

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	c;
	char	str[70000];
	int		readed;
	int		i;
	int		star;
	int		len;

	if (argc == 2)
	{
		readed = read(STDIN, &c, 1);
		if (readed == -1)
			return (perror("Error"), 1);
		if (readed == 0)
			return (1);
		i = 0;
		while (readed > 0)
		{
   			str[i++] = c;
    		readed = read(STDIN, &c, 1);
    		if (readed == -1)
        		return (perror("Error: "), 1);
		}
		str[i] = '\0';
		i = 0;
		len = ft_strlen(argv[1]);
		if (len == 0)
			return (1);
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
