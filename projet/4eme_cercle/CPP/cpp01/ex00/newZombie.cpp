/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 23:02:23 by amary             #+#    #+#             */
/*   Updated: 2026/06/05 14:57:03 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie	*new_zombie;

	new_zombie = new Zombie();
	if (!new_zombie)
		return (NULL);
	new_zombie->set_name(name);
	new_zombie->announce();
	return (new_zombie);
}
