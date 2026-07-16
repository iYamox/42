/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:52:36 by amary             #+#    #+#             */
/*   Updated: 2026/07/16 14:51:26 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "animal.hpp"

class Cat : public Animal
{
	public :
		Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &other);
		~Cat();

		std::string getType(void) const;
		void makeSound(void) const;
};


#endif