/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:31:21 by amary             #+#    #+#             */
/*   Updated: 2026/07/17 13:33:08 by amary            ###   ########.fr       */
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
	
	Animal *meta = new(Animal)''
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
}
