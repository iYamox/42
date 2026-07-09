/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 00:00:00 by amary             #+#    #+#             */
/*   Updated: 2026/07/09 18:13:37 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected :
		std::string		_Name;
		unsigned int	_health;
		unsigned int	_HealthMax;
		unsigned int	_EnergyPoint;
		unsigned int	_AttackDamage;

	public :
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		ClapTrap();
		ClapTrap(const ClapTrap &cpy);
		ClapTrap &operator=(const ClapTrap &other);
		ClapTrap(std::string name);
		~ClapTrap();
};
#endif
