/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   car_constructor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:11:57 by amary             #+#    #+#             */
/*   Updated: 2026/06/02 15:39:46 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "car.hpp"

Car::Car()
{
	brand = "Toyota";
	speed = 0;
	fuel = 100;
	return ;
}

/* ====================== GETTER ====================== */

std::string	Car::get_brand()
{
	return (brand);
}

int	Car::get_speed()
{
	return (speed);
}

int	Car::get_fuel()
{
	return (fuel);
}

/* ====================== SETTER ====================== */

void	Car::set_brand(std::string new_brand)
{
	Car::brand = new_brand;
	return;
}

void	Car::set_speed(int new_speed)
{
	Car::speed = new_speed;
	return ;
}

void	Car::set_fuel(int new_fuel)
{
	Car::fuel = new_fuel;
	return ;
}

/* ====================== FONCTIONS ====================== */

void	Car::accelerate(int amount)
{
	if (Car::fuel < amount)
	{
		std::cout << "Fuel is empty !" << std::endl;
		return ;
	}
	speed += amount;
	fuel -= amount;
	std::cout << "Okay we accelerate VROUUUUUUUM " << std::endl;
	return ;
}

void	Car::displayStatus()
{
	std::cout << "Brand of car is " << Car::get_brand() << std::endl;
	std::cout << "Speed of the car is " << Car::get_speed() <<std::endl;
	if (Car::fuel <= 0)
		std::cout << "Fuel is empty" << std::endl;
	else
		std::cout << "Fuel in the car is " << Car::fuel << std::endl;
	return ;
}
