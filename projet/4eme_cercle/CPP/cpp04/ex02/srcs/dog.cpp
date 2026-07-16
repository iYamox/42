/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:44:16 by amary             #+#    #+#             */
/*   Updated: 2026/07/16 18:25:28 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*copy._brain);
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog constructor by operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

std::string Dog::getType(void) const
{
	return (_type);
}

void Dog::makeSound(void) const
{
	std::cout << "Wouaf Wouaf" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea)
{
	_brain->getIdeas()[index] = idea;
}

std::string Dog::getIdea(int index) const
{
	return (_brain->getIdeas()[index]);
}
