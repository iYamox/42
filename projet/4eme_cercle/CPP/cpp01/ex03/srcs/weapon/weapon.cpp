/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 23:19:35 by amary             #+#    #+#             */
/*   Updated: 2026/06/19 23:29:38 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Weapon.hpp"

Weapon::Weapon(std::string name)
{
	type = name;
}

std::string const &Weapon::getType()
{
	return (type);
}

void	Weapon::setType(std::string new_name)
{
	type = new_name;
}
