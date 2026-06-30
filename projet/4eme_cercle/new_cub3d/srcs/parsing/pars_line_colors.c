/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:22:13 by amkhelif          #+#    #+#             */
/*   Updated: 2026/06/24 16:07:12 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

static bool	valid_char(char *str);
static bool	count_virgule(char *str);
static bool	convert_color(t_info *info, char *str, int indice, int i);
static bool	valid_number(int *tab);
static bool	len_dbl_tab(char **tab);

bool	pars_line(t_info *info)
{
	if (info->config.ceiling == NULL || info->config.floor == NULL)
		return (print_error(ERROR_COLOR), true);
	else if (count_virgule(info->config.ceiling)
		|| count_virgule(info->config.floor))
		return (print_error(ERROR_COLOR), true);
	else if (valid_char(info->config.ceiling) || valid_char(info->config.floor))
		return (print_error(ERROR_COLOR), true);
	else if (convert_color(info, info->config.ceiling, 0, 0))
		return (true);
	else if (convert_color(info, info->config.floor, 1, 0))
		return (true);
	return (false);
}

static bool	convert_color(t_info *info, char *str, int indice, int i)
{
	info->dbl_color = ft_split(str, ',');
	if (info->dbl_color == NULL ) // check len
		return (print_error(ERROR_MALLOC),true);
	if (len_dbl_tab(info->dbl_color))
		return (print_error(ERROR_COLOR), true);
	if (indice == 0)
	{
		while (info->dbl_color[i])
		{
			info->config.c_rgb[i] = ft_atoi(info->dbl_color[i]);
			i++;
		}
		if (valid_number(info->config.c_rgb))
			return (print_error(ERROR_COLOR),true); // affiche msg
	}
	else
	{
		while (info->dbl_color[i])
		{
			info->config.f_rgb[i] = ft_atoi(info->dbl_color[i]);
			i++;
		}
		if (valid_number(info->config.f_rgb))
			return (print_error(ERROR_COLOR),true); // affiche msg
	}
	return (false);
}

static bool	len_dbl_tab(char **tab)
{
	int	i;

	if (!tab)
		return (true);
	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
		return (true);
	return (false);
}

static bool	valid_number(int *tab)
{
	int	i;

	i = 0;
	while (i <= 2)
	{
		if (tab[i] < 0 || tab[i] > 255)
			return (true);
		i++;
	}
	return (false);
}

static bool	valid_char(char *str)
{
	int	i;

	if (str == NULL)
		return (true);
	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ',' || str[i] == ' '
			|| str[i] == '\t')
			i++;
		else
			return (true);
	}
	return (false);
}

static bool	count_virgule(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (true);
	while (str[i])
	{
		if (str[i] == ',')
		{
			if (!ft_isdigit(str[i + 1]))
				return (true);
			else
				count++;
		}
		i++;
	}
	if (count != 2)
		return (true);
	return (false);
}

bool	extract_rgb(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i])
	{
		if (ft_strncmp(info->map[i], "F ", 2) == 0)
			info->config.floor = ft_strcpy_color(info->map[i]);
		else if (ft_strncmp(info->map[i], "C ", 2) == 0)
			info->config.ceiling = ft_strcpy_color(info->map[i]);
		i++;
	}
	if (pars_line(info))
		return (true);
	// printf("%s\n", info->config.floor);
	// printf("%s\n", info->config.ceiling);
	return (false);
}
