/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:14:14 by amary             #+#    #+#             */
/*   Updated: 2026/07/16 16:41:28 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	_type = "Animal";
}

Animal::Animal(const Animal &copy)
{
	_type = copy._type;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal constructor by operator called" << std::endl;

	if (this != &other)
		_type = other._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor by operator called" << std::endl;
}

std::string Animal::getType(void) const
{
	return (_type);
}
