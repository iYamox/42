/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 18:47:13 by amary             #+#    #+#             */
/*   Updated: 2026/06/14 18:57:05 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << str << std::endl;
	std::cout << "The string adress is " << &str << std::endl;
	std::cout << "The memory adress held by stringPTR is " << *stringPTR << std::endl;
	std::cout << "The memory adress held by stringREF " << stringREF << std::endl;
	
	return (0);
}
