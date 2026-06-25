/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_contact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:14:40 by amary             #+#    #+#             */
/*   Updated: 2026/06/25 16:56:15 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/PhoneBook.hpp"

/* ================ GETTER ================ */

std::string Contact::get_name()
{
	return (name);
}

std::string Contact::get_last_name()
{
	return (last_name);
}

std::string	Contact::get_nick_name()
{
	return (nick_name);
}

std::string	Contact::get_phone_number()
{
	return (phone_number);
}

std::string	Contact::get_darkest_secret()
{
	return (darkest_secret);
}

/* ================ SETTER ================ */

void	Contact::set_name(std::string new_name)
{
	name = new_name;
	return ;
}

void	Contact::set_last_name(std::string new_lastName)
{
	last_name = new_lastName;
	return ;
}

void	Contact::set_nick_name(std::string new_nickName)
{
	nick_name = new_nickName;
	return ;
}

void	Contact::set_phone_number(std::string new_phoneNumber)
{
	phone_number = new_phoneNumber;
	return ;
}

void	Contact::set_darkest_secret(std::string new_darkestSecret)
{
	darkest_secret = new_darkestSecret;
	return ;
}
