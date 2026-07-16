/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:58:49 by amary             #+#    #+#             */
/*   Updated: 2026/07/16 17:54:13 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private :
		Brain *_brain;

	public :
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &other);
		~Dog();

		std::string getType(void) const;
		void		makeSound(void) const;

		/* ============ Brain access (for deep copy testing) ============ */

		void		setIdea(int index, const std::string &idea);
		std::string	getIdea(int index) const;
};

#endif