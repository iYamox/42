/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:22:13 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/06 13:13:20 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
		if (extract_rgb_2(info, info->map[i], &found_c, &found_f))
			return (true);
		i++;
	}
	if (!found_c || !found_f)
		return (print_error("Error\nMissing C or F color\n"), true);
	return (false);
}

bool	extract_rgb_2(t_info *info, char *line, int *c, int *f)
{
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (*c)
			return (print_error("Error\nDuplicate C color\n"), true);
		if (convert_color(info, line + 2, 0))
			return (true);
		*c = 1;
	}
	else if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (*f)
			return (print_error("Error\nDuplicate F color\n"), true);
		if (convert_color(info, line + 2, 1))
			return (true);
		*f = 1;
	}
	return (false);
}
