/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 13:26:03 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/03 13:32:14 by amkhelif         ###   ########.fr       */
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
	else if (check_map_chars(info, 0) || check_map_closed(info))
		return (true);
	return (false);
}

static int	check_texture(t_info *info)
{
	if (info->config.ea_texture == NULL || info->config.no_texture == NULL
		|| info->config.we_texture == NULL || info->config.so_texture == NULL)
		return (print_error(ERROR_TEXTURE), true);
	else if (info->config.ea_texture[0] == '\0'
		|| info->config.no_texture[0] == '\0'
		|| info->config.we_texture[0] == '\0'
		|| info->config.so_texture[0] == '\0')
		return (print_error(ERROR_TEXTURE), true);
	else if (check_open_file(info->config.we_texture)
		|| check_open_file(info->config.so_texture)
		|| check_open_file(info->config.no_texture)
		|| check_open_file(info->config.ea_texture))
		return (print_error(ERROR_TEXTURE), true);
	return (false);
}

bool	check_open_file(char *path)
{
	int	len;
	int	fd;

	if (!path)
		return (true);
	len = ft_strlen(path);
	if (len < 5)
		return (true);
	if (path[len - 4] != '.' || path[len - 3] != 'x' || path[len - 2] != 'p'
		|| path[len - 1] != 'm')
		return (true);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (true);
	close(fd);
	return (false);
}

static bool	find_texture(t_info *info, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (info->config.no_texture != NULL)
			return (print_error("Error\nDuplicate NO texture\n"), true);
		info->config.no_texture = ft_strcpy_texture(line);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (info->config.ea_texture != NULL)
			return (print_error("Error\nDuplicate EA texture\n"), true);
		info->config.ea_texture = ft_strcpy_texture(line);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (info->config.we_texture != NULL)
			return (print_error("Error\nDuplicate WE texture\n"), true);
		info->config.we_texture = ft_strcpy_texture(line);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (info->config.so_texture != NULL)
			return (print_error("Error\nDuplicate SO texture\n"), true);
		info->config.so_texture = ft_strcpy_texture(line);
	}
	return (false);
}

bool	extract_texture(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i])
	{
		if (find_texture(info, info->map[i]))
			return (true);
		i++;
	}
	if (check_texture(info))
		return (true);
	return (false);
}
