/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:30:38 by amary             #+#    #+#             */
/*   Updated: 2026/06/25 19:19:08 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
	 std::cout << "Default constructor called\n" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    value = copy.value; // ou *this = copy je sais pas
	 std::cout << "copy constructor called\n" << std::endl;
}

int Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called\n" << std::endl;
    return (value);
}

void Fixed::setRawBits(int const row)
{
    value = row;
    return ;
}
