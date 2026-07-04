/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:38:17 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/03 12:02:08 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

char	*ft_strcpy(char *str)
{
	char	*new_str;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(str) + 1;
	new_str = malloc(size * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strcpy_texture(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*new_str;

	if (str[0] == '\0')
		return (NULL);
	len = ft_strlen(str);
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 3;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	j = 0;
	while (str && str[i] && str[i] != '\t' && str[i] != ' ')
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

char	*ft_strcpy_color(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*new_str;

	if (str[0] == '\0')
		return (NULL);
	len = ft_strlen(str);
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 2;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	j = 0;
	while (str && str[i] && str[i] != '\t' && str[i] != ' ' && str[i] != '\r')
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}
