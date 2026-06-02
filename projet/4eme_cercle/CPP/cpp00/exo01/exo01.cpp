/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exo01.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:19:18 by amary             #+#    #+#             */
/*   Updated: 2026/06/01 14:52:37 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/exo01.hpp"

void	get_arg(t_contact_stock	*contact)
{
	while (1)
	{
		std::cout << "Name : "; 
		std::getline(std::cin, contact->name);
		if (contact->name.empty())
			std::cout << "Argument not valid" << std::endl;
		else
			break;
	}
	while (1)
	{
		std::cout << "Last Name : "; 
		std::getline(std::cin, contact->last_name);
		if (contact->last_name.empty())
			std::cout << "Argument not valid" << std::endl;
		else
			break;
	}
	while (1)
	{
		std::cout << "Nick Name : "; 
		std::getline(std::cin, contact->nick_name);
		if (contact->nick_name.empty())
			std::cout << "Argument not valid" << std::endl;
		else
			break;
	}
	while (1)
	{
		std::cout << "Phone Number : "; 
		std::getline(std::cin, contact->phone_number);
		if (contact->phone_number.empty())
			std::cout << "Argument not valid" << std::endl;
		else if (contact->phone_number.size() < 10)
			std::cout << "Number phone error" << std::endl;
		else
			break;
	}
	while(1)
	{
		std::cout << "Darkest Secret : "; 
		std::getline(std::cin, contact->darkest_secret);
		if (contact->darkest_secret.empty())
			std::cout << "Argument not valid" << std::endl;
		else
			break;
	}
	return ;
}

int	main(void)
{
	PhoneBook phone_book;
	std::string	command;
	t_contact_stock	contact;
	
	while(1)
	{
		std::cout << "Enter a command : ";
		std::getline(std::cin, command);
		
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
		{
			get_arg(&contact);
			phone_book.ADD(contact.name, contact.last_name, contact.nick_name, contact.phone_number, contact.darkest_secret);
		}
		else if (command == "SEARCH")
			phone_book.search();
		else
			std::cout << "Bad command" << std::endl;
	}
	return (0);
}
