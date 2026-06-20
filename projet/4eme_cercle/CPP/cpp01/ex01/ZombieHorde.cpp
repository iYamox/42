/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:29:21 by amary             #+#    #+#             */
/*   Updated: 2026/06/05 15:44:16 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*HordeZombie;
	int		i;

	HordeZombie = new Zombie[N];
	i = 0;
	while (i < N)
	{
		HordeZombie[i].set_name(name);
		i++;
	}
	return (HordeZombie);
}
