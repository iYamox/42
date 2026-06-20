/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 21:10:15 by amary             #+#    #+#             */
/*   Updated: 2026/06/19 23:56:02 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private :
		Weapon		&Pweapon;
		std::string	Pname;
	public :
		void	attack(void);
		HumanA(std::string name, Weapon &weapon);
};

#endif