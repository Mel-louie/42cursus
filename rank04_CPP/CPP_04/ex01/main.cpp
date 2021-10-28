/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:27:25 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/28 15:42:43 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClassAnimal.hpp"
#include "ClassDog.hpp"
#include "ClassCat.hpp"
#include "ClassBrain.hpp"

void	testAnimalsSounds()
{
	std::cout << "<====================== ANIMALS TESTS BASICS ======================>" << std::endl;
	std::cout << std::endl;
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
	std::cout << std::endl;
	delete meta;
}

void	testIdeas()
{
	std::cout << "<====================== ANIMALS TESTS DEFAULT IDEAS ======================>" << std::endl;
	std::cout << std::endl;
	
	Dog*	dog = new Dog();
	std::cout << std::endl;
	Cat*	cat = new Cat();
	std::cout << std::endl;
	
	std::cout << "<-------- display dog's default ideas ------->" << std::endl;
	dog->getBrain()->displayIdeas();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "<-------- display cat's default ideas ------->" << std::endl;
	cat->getBrain()->displayIdeas();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "<-------- set dog with new ideas and display them ------->" << std::endl;
	dog->getBrain()->setIdeas("WAF WAF WAF");
	dog->getBrain()->displayIdeas();
	std::cout << std::endl;
	std::cout << std::endl;

	delete dog;
	std::cout << std::endl;
	delete cat;	
}

void deepCopyTest()
{
	std::cout << "<====================== DEEP COPY TEST ======================>" << std::endl;
	std::cout << std::endl;

	Cat cat;
	Dog dog;
	std::cout << std::endl;

	cat.getBrain()->setIdeas("Meow");
	cat.getBrain()->displayIdeas();
	std::cout << std::endl;
	std::cout << std::endl;
	dog.getBrain()->setIdeas("WAF");
	dog.getBrain()->displayIdeas();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Begining of the scope --> {" << std::endl;
	{
		std::cout << "[Init Cat tmp = cat and display his ideas:]";
		std::cout << std::endl;
		std::cout << std::endl;

		Cat tmp = cat;
		std::cout << std::endl;
		tmp.getBrain()->displayIdeas();
		std::cout << std::endl;
		std::cout << std::endl;
		
		std::cout << "[Init Dog tmpd = dog and display his ideas:]";
		std::cout << std::endl;
		std::cout << std::endl;

		Dog tmpd = dog;
		std::cout << std::endl;
		tmpd.getBrain()->displayIdeas();
		std::cout << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "} <-- End of the scope" << std::endl;
	std::cout << std::endl;
	std::cout << "Does the cat->getBrain()->displayIdeas(), still have is brain:" << std::endl;
	cat.getBrain()->displayIdeas();
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Does the dog->getBrain()->displayIdeas(), still have is brain:" << std::endl;
	dog.getBrain()->displayIdeas();
	
	std::cout << std::endl;
	std::cout << std::endl;
}

void	testArray()
{
	std::cout << "<====================== ARRAY OF ANIMALS ======================>" << std::endl;

	int	nb_animals = 6;
	Animal*	ani[nb_animals];
	std::cout << std::endl;

	std::cout << "<-------- Create an array of " << nb_animals << " ------->" << std::endl;
	std::cout << "it should have " << nb_animals / 2 << " dogs and " << nb_animals / 2 << " cats." << std::endl;
	std::cout << "(the nb of animals should obviously be an even number)" << std::endl;
	std::cout << std::endl;

	std::cout << "<-------- Filling the array ------->" << std::endl;
	int i = -1;
	while (++i < nb_animals)
	{
		std::cout << "Animal #" << i << std::endl;
		if (i % 2 == 0)
			ani[i] = new Dog();
		else
			ani[i] = new Cat();
		std::cout << std::endl;
	}
	
	std::cout << "<-------- Check animals types (ani[i]->getType()) ------->" << std::endl;
	i = -1;
	while (++i < nb_animals)
	{
		std::cout << "Animal " << i << " " << ani[i]->getType();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//to have no leaks
	i = -1;
	while (++i < nb_animals)
		delete ani[i];
}

int main()
{
	
	testAnimalsSounds();
	std::cout << "<============================================================>" << std::endl;
	std::cout << std::endl;
	testIdeas();
	std::cout << "<============================================================>" << std::endl;
	std::cout << std::endl;
	deepCopyTest();
	std::cout << "<============================================================>" << std::endl;
	std::cout << std::endl;
	testArray();
	std::cout << "<============================================================>" << std::endl;
	std::cout << std::endl;

	//check leaks on macos
	system("leaks animals");
	
	return (0);
}