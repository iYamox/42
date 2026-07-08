/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:24:42 by amary             #+#    #+#             */
/*   Updated: 2026/07/08 19:22:21 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	
	_Name = "None";
	_AttackDamage = 0;
	_EnergyPoint = 10;
	_health = 10;
}

ClapTrap::ClapTrap(const ClapTrap &cpy)
{
	std::cout << "copy constructor called" << std::endl;
	
	this->_Name = cpy._Name;
	this->_AttackDamage = cpy._AttackDamage;
	this->_EnergyPoint = cpy._EnergyPoint;
	this->_health = cpy._health;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "constuctor by assigment called" << std::endl;

	if (this != &other)
	{
		this->_Name = other._Name;
		this->_AttackDamage = other._AttackDamage;
		this->_EnergyPoint = other._EnergyPoint;
		this->_health = other._health;
	}
	return (*this);
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "constructor by name called" << std::endl;
	
	_Name = name;
	_AttackDamage = 0;
	_EnergyPoint = 10;
	_health = 10;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	std::cout << "attack function called" << std::endl;

	if (_EnergyPoint < 1)
	{
		std::cout << "can't attack zebi" << std::endl;
		return ;
	}
	std::cout << _Name << " attacks " << target << " causing " << _AttackDamage << " points of damage !" << std::endl;
	_EnergyPoint--;
	std::cout << "Available energy " << _EnergyPoint << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "takeDamage function called" << std::endl;

	if (_health <= amount)
		_health = 0;
	else
		_health -= amount;
	
	std::cout << "Heal is " << _health << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "beRepaired called" << std::endl;
	
	if (_EnergyPoint < 1)
	{
		std::cout << "can't repaired zebi" << std::endl;
		return ;
	}
	if ((amount + _health) > 10)
	{
		std::cout << "Health is max" << std::endl;
		_health = 10;
		_EnergyPoint--;
		return ;
	}
	else
	{
		_health += amount;
		_EnergyPoint--;
		std::cout << "Health is " << _health << std::endl;
	}

	std::cout << "Available energy " << _EnergyPoint << std::endl;
}
