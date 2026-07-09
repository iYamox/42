/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 00:00:00 by amary             #+#    #+#             */
/*   Updated: 2026/07/09 17:38:44 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int	main(void)
{
	std::cout << "\n----- ClapTrap -----\n" << std::endl;

	ClapTrap clap("Clappy");
	
	clap.attack("Dummy");
	clap.takeDamage(5);
	clap.beRepaired(2);

	std::cout << std::endl << "----- ScavyTrap -----\n" << std::endl;
	
	ScavTrap scav("Scavy");
	
	scav.attack("Dummy");
	scav.guardGate();
	scav.takeDamage(40);
	scav.beRepaired(10);

	std::cout << std::endl << "----- Fraggy -----\n" << std::endl;
	
	FragTrap frag("Fraggy");
	
	frag.attack("Dummy");
	frag.highFivesGuys();
	frag.takeDamage(40);
	frag.beRepaired(10);

	std::cout << std::endl << "=== End of scope, destruction order ===" << std::endl;
	return (0);
}
