/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:31:21 by amary             #+#    #+#             */
/*   Updated: 2026/07/16 18:53:42 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/animal.hpp"
#include "../includes/cat.hpp"
#include "../includes/dog.hpp"
#include "../includes/wrongAnimal.hpp"
#include "../includes/wrongCat.hpp"

int main()
{
	Animal *Zoo[6];
	
	for (int i = 0; i < 6; i++)
	{
		if (i % 2)
			Zoo[i] = new Dog();
		else
			Zoo[i] = new Cat();
	}
	for (int i = 0; i < 6; i++)
		Zoo[i]->makeSound();
	for (int i = 0; i < 6; i++)
		delete Zoo[i];

	std::cout << "\n--- Deep copy test ---" << std::endl;

	Dog original;
	original.setIdea(0, "original idea");

	Dog copy(original); // copy constructor

	std::cout << "original idea: " << original.getIdea(0) << std::endl;
	std::cout << "copy idea before change: " << copy.getIdea(0) << std::endl;

	original.setIdea(0, "changed idea");

	std::cout << "original idea after change: " << original.getIdea(0) << std::endl;
	std::cout << "copy idea after change: " << copy.getIdea(0) << std::endl;
}
