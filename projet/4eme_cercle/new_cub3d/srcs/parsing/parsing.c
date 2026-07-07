/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:20:56 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/03 16:32:54 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	check_all(char *file_path, t_info *info)
{
	if (check_name_file(file_path, info))
		return (true);
	if (read_file(info))
		return (true);
	if (extract_config(info))
		return (true);
	return (false);
}
