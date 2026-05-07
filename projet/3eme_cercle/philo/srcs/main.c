/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:46:19 by amary             #+#    #+#             */
/*   Updated: 2026/05/07 16:16:40 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (printf("Error: Arguments\n"), 1);
	if (!init_all(&data, argc, argv))
		return (1);
	if (!start_simulation(&data))
		return (1);
	return (0);
}
