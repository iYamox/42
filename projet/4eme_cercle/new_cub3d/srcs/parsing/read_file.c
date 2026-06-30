/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:57:23 by amkhelif          #+#    #+#             */
/*   Updated: 2026/06/25 14:58:55 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

// create function for open file

bool	open_file(t_info *info)
{
	info->fd = open(info->file_name, O_RDONLY);
	if (info->fd < 0)
		return (print_error(ERROR_OPEN_FILE), true);
	return (false);
}

bool	read_file(t_info *info)
{
	int		size;
	char	*buffer;
	char	*all_file;

	size = 1;
	all_file = NULL;
	if (open_file(info))
		return (true);
	while (size > 0)
	{
		buffer = malloc(100 * sizeof(char));
		if (buffer == NULL)
			return (print_error(ERROR_MALLOC), true);
		size = read(info->fd, buffer, 99);
		if (size < 0)
			return (error_read(info), free(buffer), true);
		buffer[size] = '\0';
		all_file = ft_strjoin(all_file, buffer);
		free(buffer);
	}
	info->map = ft_split(all_file, '\n');
	if (info->map == NULL)
		return (print_error(ERROR_MALLOC), true);
	return (false);
}

// check if file name is good
bool	check_name_file(char *str, t_info *info)
{
	int len;

	len = ft_strlen(str);
	if (len <= 4) // if name file is too short
		return (print_error(ERROR_NAME_FILE), true);
	else if (str[len - 4] != '.' || str[len - 3] != 'c' || str[len - 2] != 'u'
		|| str[len - 1] != 'b')
		return (print_error(ERROR_NAME_FILE), true);
	info->file_name = str;
	return (false);
}