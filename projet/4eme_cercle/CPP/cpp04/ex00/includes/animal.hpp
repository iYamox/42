/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:42:38 by amary             #+#    #+#             */
/*   Updated: 2026/07/17 13:02:27 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected :
		std::string _type;

	public :
		Animal();
		Animal(const Animal &copy);
		Animal &operator=(const Animal &other);
		virtual ~Animal();
		
		std::string	getType(void) const; // Le const assure que je modifie rien a l interieur
		virtual void makeSound(void) const;
};

#endif