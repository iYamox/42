/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 23:53:25 by amary             #+#    #+#             */
/*   Updated: 2026/06/20 00:00:25 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : Pweapon(weapon)
{
    Pname = name;
}

void	HumanA::attack(void)
{
	std::cout << Pname << " attacks with their " << Pweapon.getType() << std::endl;
}
