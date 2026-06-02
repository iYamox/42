/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   car.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:04:39 by amary             #+#    #+#             */
/*   Updated: 2026/06/02 15:18:16 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAR_HPP
# define CAR_HPP

#include <iostream>
#include <cstdlib>

class Car
{
	private :
		std::string brand;
		int			speed;
		int			fuel;
	
	public :
		std::string	get_brand();
		int			get_speed();
		int			get_fuel();
		void		set_brand(std::string new_brand);
		void		set_speed(int new_speed);
		void		set_fuel(int new_fuel);
		void		accelerate(int amount);
		void		displayStatus();
		Car();
};

#endif