/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 20:18:06 by amary             #+#    #+#             */
/*   Updated: 2026/07/08 20:52:38 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

// J'ecrase les donnees de la class parents
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;

	_Name = "None";
	_health = 100;
	_EnergyPoint = 50;
	_AttackDamage = 20;
}

// Pourquoi ici je fais pas comme le constructeur par defaut ? Pk obligé de faire :clapTrape(name) quel utiliter
// On lui donne le meme nom genre ?
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor by name called" << std::endl;

	_health = 100;
	_EnergyPoint = 50;
	_AttackDamage = 20;
}

// Ici pareil ?
ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap(cpy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;

	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap attack function called" << std::endl;

	if (_EnergyPoint < 1)
	{
		std::cout << "can't attack, no energy left" << std::endl;
		return ;
	}
	std::cout << _Name << " attacks " << target << " with its ScavTrap sword, causing "  << _AttackDamage << " points of damage !" << std::endl;
	_EnergyPoint--;
}

void	ScavTrap::guardGate()
{
	std::cout << _Name << " is now in Gate keeper mode" << std::endl;
}
