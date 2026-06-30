/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:38:17 by amkhelif          #+#    #+#             */
/*   Updated: 2026/06/25 12:42:46 by amkhelif         ###   ########.fr       */
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

// char	*ft_strcpy(char *str)
// {
// 	int		i;
// 	int		len;
// 	char	*new_str;

// 	// printf("je \n %s\n", str);
// 	if (str[0] == '\0')
// 		return (NULL);
// 	new_str = NULL;
// 	len = ft_strlen(str);
// 	i = 0;
// 	new_str = malloc(len + 1 * sizeof(char));
// 	if (new_str == NULL)
// 		while (str && str[i])
// 		{
// 			new_str[i] = str[i];
// 			i++;
// 		}
// 	new_str[i] = '\0';
// 	return (new_str);
// }

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
	while (str && str[i])
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
	int i;
	int j;
	int len;
	char *new_str;

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
	while (str && str[i])
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}