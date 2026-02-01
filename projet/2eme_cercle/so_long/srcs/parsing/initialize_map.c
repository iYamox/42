/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:30:33 by amary             #+#    #+#             */
/*   Updated: 2026/01/10 21:37:46 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	initialize_map(char *str, t_map *map)
{
	int		fd;
	char	*line;
	int		j;

	j = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (close (fd), exit(0));
	line = get_next_line(fd);
	if (!line || ft_strlen(line) < 2)
		exit(1);
	map->width = ft_strlen(line) - 1;
	while (line)
	{
		j++;
		free(line);
		line = get_next_line(fd);
	}
	map->grid = malloc ((j + 1) * sizeof(char *));
	if (!map->grid)
		return (write(2, "Grid allocation error\n", 23), close(fd), exit (0));
	map->grid[j] = NULL;
	map->height = j;
	close(fd);
	return ;
}
