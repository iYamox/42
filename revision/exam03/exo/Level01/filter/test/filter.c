/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:04:51 by amary             #+#    #+#             */
/*   Updated: 2026/02/24 13:17:11 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	int		j;
	int 	len;
	int		readed;
	char	c;
	char	line[70000];

	if (argc == 2)
	{
		readed = read(STDIN, &c, 1);
		if (readed == 0)
			return (0);
		if (readed == -1)
			return (1);
		i = 0;
		while (readed)
		{
			line[i++] = c;
			readed = read(STDIN, &c, 1);
			if (readed == -1)
				return (1);
		}
		line[i] = '\0';
		i = 0;
		len =  ft_strlen(argv[1]);
		if (len == 0)
			return (1);
		while (line[i])
		{
			if (ft_strncmp(argv[1], &line[i], len) == 0)
			{
				j = 0;
				while (j < len)
				{
					write(1, "*", 1);
					j++;
					i++;
				}
			}
			else
				write(1, &line[i++], 1);
		}
	}
	
}
