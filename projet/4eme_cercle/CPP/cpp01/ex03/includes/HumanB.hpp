/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 23:14:25 by amary             #+#    #+#             */
/*   Updated: 2026/06/20 00:05:11 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private :
		Weapon		*Pweapon;
		std::string	Pname;
	public :
		void	setWeapon(Weapon &weapon);
		void	attack(void);
		HumanB(std::string name);
};

#endif