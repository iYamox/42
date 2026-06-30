/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:28:03 by amary             #+#    #+#             */
/*   Updated: 2026/06/29 14:02:17 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private :
        int                 value;
        static const int    fractionalBits = 8;

    public :
        Fixed();
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &assign);
        ~Fixed();
        
        int getRawBits(void);
        void setRawBits(int const raw);
};

#endif