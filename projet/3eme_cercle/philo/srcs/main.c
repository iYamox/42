/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:37:08 by amary             #+#    #+#             */
/*   Updated: 2026/06/18 14:52:18 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	table = malloc(1 * sizeof(t_table));
	if (!table)
		return (1);
	if (!ft_parsing(argc, argv, table))
		return (write(1, "Error\n", 7), ft_cleanup(table), 1);
	if (!ft_init(table))
		return (ft_cleanup_init(table), 1);
	if (!ft_start(table))
		return (ft_cleanup_init(table), 1);
	ft_cleanup(table);
	return (0);
}
