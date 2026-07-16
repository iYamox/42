/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:33:03 by amary             #+#    #+#             */
/*   Updated: 2026/07/16 18:15:00 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "copy Brain constructor called" << std::endl;

	for (int i = 0; i < 100 ;i++)
		ideas[i] = copy.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain constructor by operator called" << std::endl;
	
	if (this != &other)
	{
		for (int i = 0; i < 100 ;i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "brain destructor called" << std::endl;
}

std::string *Brain::getIdeas(void)
{
	return (ideas);
}
