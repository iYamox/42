/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 13:26:03 by amkhelif          #+#    #+#             */
/*   Updated: 2026/06/25 13:50:15 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

bool	extract_config(t_info *info)
{
	if (extract_texture(info))
		return (true);
	else if (extract_rgb(info))
		return (true);
	else if (extract_map(info))
		return (true);
	else if (check_map_chars(info) || check_map_closed(info))
		return (true);
	return (false);
}
static int	check_texture(t_info *info)
{
	if (info->config.ea_texture == NULL || info->config.no_texture == NULL
		|| info->config.we_texture == NULL || info->config.so_texture == NULL)
		return (print_error(ERROR_TEXTURE), true);
	if (info->config.ea_texture[0] == '\0' || info->config.no_texture[0] == '\0'
		|| info->config.we_texture[0] == '\0'
		|| info->config.so_texture[0] == '\0')
		return (print_error(ERROR_TEXTURE), true);
	return (false);
}

bool	extract_texture(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i])
	{
		if (ft_strncmp(info->map[i], "NO ", 3) == 0)
			info->config.no_texture = ft_strcpy_texture(info->map[i]);
		else if (ft_strncmp(info->map[i], "EA ", 3) == 0)
			info->config.ea_texture = ft_strcpy_texture(info->map[i]);
		else if (ft_strncmp(info->map[i], "WE ", 3) == 0)
			info->config.we_texture = ft_strcpy_texture(info->map[i]);
		else if (ft_strncmp(info->map[i], "SO ", 3) == 0)
			info->config.so_texture = ft_strcpy_texture(info->map[i]);
		i++;
	}
	// print_textures(info);
	if (check_texture(info))
		return (true);
	return (false);
}
