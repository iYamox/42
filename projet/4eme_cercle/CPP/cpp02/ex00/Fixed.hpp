/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:28:03 by amary             #+#    #+#             */
/*   Updated: 2026/06/22 13:31:55 by amary            ###   ########.fr       */
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
        // Constructor copy
        // copy assignment operator overload
        ~Fixed();
}

#endif