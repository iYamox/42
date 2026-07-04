/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:22:13 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/03 16:33:30 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

static void	fill_rgb(int *rgb, char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		rgb[i] = ft_atoi(split[i]);
		i++;
	}
}

static bool	convert_color(t_info *info, char *str, int indice)
{
	int	*target_rgb;

	info->dbl_color = ft_split(str, ',');
	if (!info->dbl_color || len_dbl_tab(info->dbl_color))
	{
		free_function(info->dbl_color);
		info->dbl_color = NULL;
		return (print_error(ERROR_COLOR), true);
	}
	if (indice == 0)
		target_rgb = info->config.c_rgb;
	else
		target_rgb = info->config.f_rgb;
	fill_rgb(target_rgb, info->dbl_color);
	free_function(info->dbl_color);
	info->dbl_color = NULL;
	if (valid_number(target_rgb))
		return (print_error(ERROR_COLOR), true);
	return (false);
}

bool	extract_rgb(t_info *info)
{
	int	i;
	int	found_c;
	int	found_f;

	i = 0;
	found_c = 0;
	found_f = 0;
	while (info->map[i])
	{
		if (ft_strncmp(info->map[i], "C ", 2) == 0)
		{
			if (found_c)
				return (print_error("Error\nDuplicate C color\n"), true);
			if (convert_color(info, info->map[i] + 2, 0))
				return (true);
			found_c = 1;
		}
		else if (ft_strncmp(info->map[i], "F ", 2) == 0)
		{
			if (found_f)
				return (print_error("Error\nDuplicate F color\n"), true);
			if (convert_color(info, info->map[i] + 2, 1))
				return (true);
			found_f = 1;
		}
		i++;
	}
	if (!found_c || !found_f)
		return (print_error("Error\nMissing C or F color\n"), true);
	return (false);
}
