/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:26:50 by amary             #+#    #+#             */
/*   Updated: 2026/07/16 18:25:06 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	_brain = new Brain();
	_type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_type = copy._type;
	_brain = new Brain(*copy._brain);
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat constructor by operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

std::string Cat::getType(void) const
{
	return (_type);
}

void Cat::makeSound(void) const
{
	std::cout << "meow meow" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea)
{
	_brain->getIdeas()[index] = idea;
}

std::string Cat::getIdea(int index) const
{
	return (_brain->getIdeas()[index]);
}
