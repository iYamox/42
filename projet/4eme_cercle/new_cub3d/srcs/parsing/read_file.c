/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:57:23 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/03 13:35:30 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

bool	open_file(t_info *info)
{
	info->fd = open(info->file_name, O_RDONLY);
	if (info->fd < 0)
		return (print_error(ERROR_OPEN_FILE), true);
	return (false);
}

static char	*read_all_lines(t_info *info)
{
	int		size;
	char	*buffer;
	char	*all_file;
	char	*tmp;

	all_file = NULL;
	buffer = malloc(100 * sizeof(char));
	if (!buffer)
		return (close(info->fd), print_error(ERROR_MALLOC), NULL);
	size = 1;
	while (size > 0)
	{
		size = read(info->fd, buffer, 99);
		if (size < 0)
			return (close(info->fd), free(buffer), free(all_file), error_read(),
				NULL);
		buffer[size] = '\0';
		tmp = all_file;
		all_file = ft_strjoin(all_file, buffer);
		free(tmp);
	}
	return (free(buffer), close(info->fd), all_file);
}

bool	read_file(t_info *info)
{
	char	*all_file;

	if (open_file(info))
		return (true);
	all_file = read_all_lines(info);
	if (!all_file)
		return (true);
	info->map = ft_split(all_file, '\n');
	free(all_file);
	if (!info->map)
		return (print_error(ERROR_MALLOC), true);
	return (false);
}

// check if file name is good
bool	check_name_file(char *str, t_info *info)
{
	int	len;

	len = ft_strlen(str);
	if (len <= 4)
		return (print_error(ERROR_NAME_FILE), true);
	else if (str[len - 4] != '.' || str[len - 3] != 'c' || str[len - 2] != 'u'
		|| str[len - 1] != 'b')
		return (print_error(ERROR_NAME_FILE), true);
	info->file_name = str;
	return (false);
}
