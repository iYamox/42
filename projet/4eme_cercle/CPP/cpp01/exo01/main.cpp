/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:17:02 by amary             #+#    #+#             */
/*   Updated: 2026/06/05 16:13:12 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie		*HordeZombie;
	int			i;
	
	std::cout << "Dans 3 secondes une orde de zombie va spawn" << std::endl;
	sleep(3);
	HordeZombie = zombieHorde(6, "Alexandre");
	i = 0;
	while (i < 6)
		HordeZombie[i++].announce();
	std::cout << "On va maintenant touuuuuuus les tuer dans 3 secondes" << std::endl;
	sleep(3);
	delete[] HordeZombie;
	return (0);
}
