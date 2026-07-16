/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:15:50 by amary             #+#    #+#             */
/*   Updated: 2026/07/16 17:31:05 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string.h>

class Brain
{
	private :
		std::string ideas[100];
	public :
		Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &other);
		~Brain();

		std::string *getIdeas(void);
};

#endif