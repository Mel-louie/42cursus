/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:27:25 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/27 23:23:14 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClassAnimal.hpp"
#include "ClassDog.hpp"
#include "ClassCat.hpp"


void	testAnimals()
{
	const Animal* meta = new Animal();
	std::cout << std::endl;

	const Animal* j = new Dog();
	std::cout << std::endl;

	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << "== There are few animals, here are their types: ==" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;

	std::cout << "== And the sounds they make: ==" << std::endl;
	i->makeSound(); std::cout << "\t, does the " << i->getType() << "." << std::endl;
	j->makeSound(); std::cout << "\t, does the " << j->getType() << "." << std::endl;
	meta->makeSound(); std::cout << "\t... does the... " << meta->getType() << "?..." << std::endl;
	std::cout << std::endl;

	std::cout << "== And now, it's time to say goodbye: ==" << std::endl;
	delete i;
	std::cout << std::endl;
	delete j;
	std::cout << std::endl;
	delete meta;
}

int main()
{
	std::cout << "<============ ANIMALS TESTS ============>" << std::endl;
	std::cout << std::endl;
	testAnimals();
	std::cout << "<=======================================>" << std::endl;
	std::cout << std::endl;

	
	return (0);
}