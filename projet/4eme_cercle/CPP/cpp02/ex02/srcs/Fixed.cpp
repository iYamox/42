/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 13:12:09 by amary             #+#    #+#             */
/*   Updated: 2026/07/07 17:50:26 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor is called" << std::endl;
    _value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "int constructor is called" << std::endl;
	// On "décale" l'entier de 8 bits vers la gauche = multiplier par 256
	_value = value << fractional_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "float constructor is called" << std::endl;
	// On multiplie par 256, et roundf arrondit à l'entier le plus proche
	_value = roundf(value * (1 << fractional_bits));
}

float	Fixed::toFloat(void) const
{
	// On divise par 256 pour retrouver le vrai nombre à virgule
	return ((float)_value / (1 << fractional_bits));
}

int	Fixed::toInt(void) const
{
	// On décale de 8 bits vers la droite = diviser par 256 (résultat entier)
	return (_value >> fractional_bits);
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

					/* Comparaisons */
					
bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other._value);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other._value);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other._value);
}

				/* Arithmétique */

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_value + other._value);
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_value - other._value);
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((int)(((long)this->_value * other._value) >> fractional_bits));
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((int)(((long)this->_value << fractional_bits) / other._value));
	return (result);
}

					/* Incrément / décrément */

Fixed	&Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_value++;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_value--;
	return (tmp);
}

				/* min / max */

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
