/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:58:49 by amary             #+#    #+#             */
/*   Updated: 2026/07/16 14:51:35 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &other);
		~Dog();

		std::string getType(void) const;
		void		makeSound(void) const;
};

#endif