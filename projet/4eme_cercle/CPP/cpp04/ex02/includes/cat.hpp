/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:52:36 by amary             #+#    #+#             */
/*   Updated: 2026/07/16 17:56:41 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private :
		Brain *_brain;

	public :
		Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &other);
		~Cat();

		std::string getType(void) const;
		void makeSound(void) const;

		/* ============ Brain access (for deep copy testing) ============ */

		void		setIdea(int index, const std::string &idea);
		std::string	getIdea(int index) const;
};


#endif