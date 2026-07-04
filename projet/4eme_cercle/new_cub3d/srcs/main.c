/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:24:59 by amkhelif          #+#    #+#             */
/*   Updated: 2026/07/03 15:17:01 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	main(int ac, char **av)
{
	static t_info	info = {0};

	if (ac != 2)
		return (print_error(ERROR_NUM_ARGV), 1);
	if (check_all(av[1], &info))
	{
		free_all(&info);
		return (1);
	}
	init_game(&info);
	return (0);
}
