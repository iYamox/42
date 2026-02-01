/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 20:28:37 by amary             #+#    #+#             */
/*   Updated: 2026/01/12 16:50:29 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map map)
{
	int	j;

	j = 0;
	while (map.grid[j])
		free(map.grid[j++]);
	free(map.grid);
	return ;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (write(2, "Error to many arguments\n", 25), 1);
	if (!is_ber(argv[1]))
		return (write(2, "Error\nNot a .ber file\n", 22), 1);
	game.map = read_map(argv[1]);
	if (!ft_parsing(&game.map))
		return (write(2, "Parsing error\n", 15), free_map(game.map), 1);
	start_game(&game);
	free_map(game.map);
	return (0);
}
