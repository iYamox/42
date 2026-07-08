/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:16:39 by amary             #+#    #+#             */
/*   Updated: 2026/07/08 19:24:45 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int	main(void)
{
	ClapTrap RobotA("Alexandre");
	ClapTrap RobotB("Matthieu");

	RobotA.attack("Matthieu");
	RobotB.takeDamage(15);
	
	RobotB.beRepaired(3);
	return (0);
}
