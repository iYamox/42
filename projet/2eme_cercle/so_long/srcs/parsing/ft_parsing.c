/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:06:16 by amary             #+#    #+#             */
/*   Updated: 2026/01/12 17:05:00 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_parsing(t_map *map)
{
	if (!is_rectangle(map))
		return (0);
	if (!is_correct_wall(map))
		return (0);
	if (!is_correct_char(map))
		return (0);
	if (!have_all_collect(map))
		return (0);
	if (!is_winable(map))
		return (write(2, "Map not winable\n", 17), 0);
	return (1);
}
