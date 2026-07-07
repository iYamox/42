/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 13:12:09 by amary             #+#    #+#             */
/*   Updated: 2026/07/07 15:09:42 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor is called" << std::endl;
    _value = 0;
}

Fixed::Fixed(const Fixed &cpy)
{
	std::cout << "constructor by copy is called" << std::endl;
	this->_value = cpy._value;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "constructor by assignment is called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
	return ;
}
