/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:02:36 by amary             #+#    #+#             */
/*   Updated: 2026/06/02 15:37:27 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "car.hpp"

int	ft_strlen(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isNumber(std::string argv)
{
	int	i;

	if (ft_strlen(argv) > 3)
		return (std::cout << "Speed too high" << std::endl, 0);
	i = 0;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (std::cout << "Accelerate argument error" <<std::endl, 0);
		i++;
	}
	return (1);
}

int	main(void)
{
	std::string command;
	std::string	speed_arg;
	Car toyota_86GT;
	int	speed;
	
	while (1)
	{
		std::cout << "What we do ? : ";
		getline(std::cin, command);
		if (command == "Accelerate")
		{
			std::cout << "who many ? : ";
			getline(std::cin, speed_arg);
			if (!ft_isNumber(speed_arg))
				return (1);
			speed = atoi(speed_arg.c_str());
			toyota_86GT.accelerate(speed);
		}
		else if (command == "Car Statut")
			toyota_86GT.displayStatus();
		else if (command == "Exit")
			break ;
		else
			std::cout << "Argument error" << std::endl;
	}
	return (0);
}
