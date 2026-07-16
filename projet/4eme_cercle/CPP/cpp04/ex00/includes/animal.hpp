/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:42:38 by amary             #+#    #+#             */
/*   Updated: 2026/07/16 16:41:19 by amary            ###   ########.fr       */
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

		/* ============ GETTER ============ */
		
		std::string	getType(void) const; // Le const assure que je modifie rien a l interieur

		/* ============ Function ============ */

		virtual void makeSound(void) const;
};

#endif