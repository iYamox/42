/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:31:21 by amary             #+#    #+#             */
/*   Updated: 2026/07/16 16:26:49 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/animal.hpp"
#include "../includes/cat.hpp"
#include "../includes/dog.hpp"
#include "../includes/wrongAnimal.hpp"
#include "../includes/wrongCat.hpp"

int main()
{
	// Dog *chien = new(Dog);
	// Animal *Zoo[2];

	// Zoo[0] = new(Dog);
	// Zoo[1] = new(Cat);
	// /* etc....*/
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete (j);
	delete (i);
	delete (meta);
}
