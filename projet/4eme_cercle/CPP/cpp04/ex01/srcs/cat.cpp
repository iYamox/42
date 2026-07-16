/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:26:50 by amary             #+#    #+#             */
/*   Updated: 2026/07/16 15:00:51 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_type = copy._type;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat constructor by operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

std::string Cat::getType(void) const
{
	return (_type);
}

void Cat::makeSound(void) const
{
	std::cout << "meow meow" << std::endl;
}
