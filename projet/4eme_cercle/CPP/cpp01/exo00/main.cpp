/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:17:26 by amary             #+#    #+#             */
/*   Updated: 2026/06/05 15:06:36 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <unistd.h>

int	main(void)
{
	Zombie	*zombie;

	std::cout << "In 5 seconds, we're going to create a zombie that will call itself and then destroy itself" << std::endl;
	sleep(5);
	randomChump("Alexandre");

	std::cout << "In 5 seconds, we're going to create a zombie in the heap and see if there are any leaks" << std::endl;
	sleep(5);
	zombie = newZombie("Riad");
	if (!zombie)
		return (1);
	std::cout << "The heap zombie has been created and will be deleted in 5 seconds" << std::endl;
	sleep(5);
	delete(zombie);
	
	return (0);
}
