/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:30:38 by amary             #+#    #+#             */
/*   Updated: 2026/06/22 14:26:05 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
    value = copy.value;
}

int Fixed::getRawBits(void)
{
    return (value);
}

void Fixed::setRawBits(int const row)
{
    value = row;
    return ;
}