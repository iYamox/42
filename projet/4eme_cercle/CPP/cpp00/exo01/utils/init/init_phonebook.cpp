/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_phonebook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:00:26 by amary             #+#    #+#             */
/*   Updated: 2026/06/01 14:52:19 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exo01.hpp"

PhoneBook::PhoneBook()
{
	i = 0;
	count = 0;
}

void	PhoneBook::ADD(std::string name, std::string last_name, std::string nick_name,  std::string phone_name, std::string darkest_secret)
{
	if (i >= 8)
		i = 0;
	all_contact[i].set_name(name);
	all_contact[i].set_last_name(last_name);
	all_contact[i].set_nick_name(nick_name);
	all_contact[i].set_phone_number(phone_name);
	all_contact[i].set_darkest_secret(darkest_secret);
	i++;
	if (count <= 8)
		count++;
	return ;
}

void	display_column(std::string str)
{
	if ((int)str.size() > 10)
		str = str.substr(0, 9) + ".";
	std::cout << std::setw(10) << std::right << str << "|";
}

void	PhoneBook::search()
{
	int			j;
	std::string	input;
	int			index;

	if (count == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	j = 0;
	while (j < count)
	{
		std::cout << std::setw(10) << std::right << j << "|";
		display_column(all_contact[j].get_name());
		display_column(all_contact[j].get_last_name());
		display_column(all_contact[j].get_nick_name());
		std::cout << std::endl;
		j++;
	}
	std::cout << "Enter index : ";
	std::getline(std::cin, input);
	while (1)
	{
		if (input.empty() || input.size() > 1 || input[0] < '0' || input[0] > '8')
		{
			std::cout << "Invalid index" << std::endl;
			std::cout << "Enter index : ";
			std::getline(std::cin, input);
			continue ;
		}
		else
		{
			index = input[0] - '0';
			if (index >= count)
			{
				std::cout << "index empty" << std::endl;
				std::cout << "Enter index : ";
				std::getline(std::cin, input);
				continue ;
			}
			else
				break ;
		}
	}
	std::cout << "Name : " << all_contact[index].get_name() << std::endl;
	std::cout << "Last Name : " << all_contact[index].get_last_name() << std::endl;
	std::cout << "Nick Name : " << all_contact[index].get_nick_name() << std::endl;
	std::cout << "Phone Number : " << all_contact[index].get_phone_number() << std::endl;
	std::cout << "Darkest Secret : " << all_contact[index].get_darkest_secret() << std::endl;
	return ;
}
