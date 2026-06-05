/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:22:12 by amary             #+#    #+#             */
/*   Updated: 2026/06/05 15:27:41 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* ================== Constructor / Destructor ================== */

Zombie::Zombie()
{
	name = "None";

	return ;
}

Zombie::~Zombie()
{
	std::cout << name << std::endl;

	return ;
}

/* ================== Getter ================== */

std::string	Zombie::get_name(void)
{
	return (name);
}

/* ================== Setter ================== */

void	Zombie::set_name(std::string new_name)
{
	name = new_name;

	return ;
}

/* ================== Fonction ================== */

void	Zombie::announce(void)
{
	std::cout << name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;

	return ;
}
