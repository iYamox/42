/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 17:12:46 by amary             #+#    #+#             */
/*   Updated: 2026/07/04 17:12:48 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    value = copy.value;
	std::cout << "copy constructor called\n" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &assign)
{
	this->value = assign.value;

	std::cout << "assign constructor called" << std::endl;
	return (*this);
}

int Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void Fixed::setRawBits(int const row)
{
    value = row;
    return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
