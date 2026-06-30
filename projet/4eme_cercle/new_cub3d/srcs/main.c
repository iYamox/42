/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:24:59 by amkhelif          #+#    #+#             */
/*   Updated: 2026/06/26 13:39:47 by amkhelif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	main(int ac, char **av)
{
	static t_info info = {0};

	if (ac != 2)
		return (print_error(error_number_argv), 1);
	if (check_all(av[1], &info))
		return (1);
	init_game(&info);
	return (0);
}