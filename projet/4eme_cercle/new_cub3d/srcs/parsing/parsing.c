/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:20:56 by amkhelif          #+#    #+#             */
/*   Updated: 2026/06/25 13:36:16 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

// main function parsing
bool	check_all(char *str, t_info *info)
{
	if (check_name_file(str, info))
		return (true);
	else if (read_file(info))
		return (true);
	else if (extract_config(info))
		return (true);
	// else if (check_rgb_values(info->config.ceiling)
	// 	|| check_rgb_values(info->config.floor))
	// 	return (true);
	return (false);
}
