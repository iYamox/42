/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 16:24:54 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/01 16:55:41 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

bool	line_is_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\r')
			return (false);
		i++;
	}
	return (true);
}

int	start_map(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i])
	{
		if (info->map[i][0] == '\0' || line_is_spaces(info->map[i])
			|| ft_strncmp(info->map[i], "NO ", 3) == 0
			|| ft_strncmp(info->map[i], "SO ", 3) == 0
			|| ft_strncmp(info->map[i], "WE ", 3) == 0
			|| ft_strncmp(info->map[i], "EA ", 3) == 0
			|| ft_strncmp(info->map[i], "F ", 2) == 0
			|| ft_strncmp(info->map[i], "C ", 2) == 0)
			i++;
		else
			break ;
	}
	return (i);
}

int	len_map(char **map, int i)
{
	int	len;

	len = 0;
	while (map[i])
	{
		len++;
		i++;
	}
	return (len);
}

bool	extract_map(t_info *info)
{
	int	i;
	int	len;

	i = start_map(info);
	len = len_map(info->map, i);
	info->map_final = malloc((len + 1) * sizeof(char *));
	if (!info->map_final)
		return (print_error(ERROR_MALLOC), true);
	len = 0;
	while (info->map[i])
	{
		info->map_final[len] = ft_strcpy(info->map[i]);
		if (info->map_final[len] == NULL)
			return (print_error(ERROR_MALLOC), true);
		i++;
		len++;
	}
	info->map_final[len] = NULL;
	return (false);
}
