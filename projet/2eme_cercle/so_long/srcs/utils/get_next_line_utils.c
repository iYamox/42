/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:55:30 by amary             #+#    #+#             */
/*   Updated: 2025/11/25 19:15:39 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	size_t	i;
	char	*dst;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	dst = malloc((len + 1) * sizeof (char));
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *tmp, char *buffer)
{
	int		i;
	int		j;
	char	*dst;

	if (!tmp)
		tmp = ft_strdup("");
	dst = malloc (ft_strlen(tmp) + ft_strlen(buffer) + 1);
	if (!dst)
		return (free(tmp), NULL);
	i = -1;
	while (tmp[++i])
		dst[i] = tmp[i];
	j = -1;
	while (buffer[++j])
		dst[i + j] = buffer[j];
	dst[i + j] = '\0';
	free(tmp);
	return (dst);
}
