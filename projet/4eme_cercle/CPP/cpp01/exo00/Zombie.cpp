/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:18:57 by amary             #+#    #+#             */
/*   Updated: 2026/06/05 14:50:11 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
	
	return ;
}

Zombie::Zombie()
{
	name = "None";
}

Zombie::~Zombie()
{
	std::cout << name << std::endl;
}

std::string	Zombie::get_name()
{
	return (name);
}

void	Zombie::set_name(std::string new_name)
{
	name = new_name;
	
	return ;
}
