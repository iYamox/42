/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:01:52 by amary             #+#    #+#             */
/*   Updated: 2026/06/20 00:15:09 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/HumanB.hpp"

HumanB::HumanB(std::string name)
{
	Pname = name;
	Pweapon = NULL;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	Pweapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << Pname << " attacks with their " << Pweapon->getType() << std::endl;
}
