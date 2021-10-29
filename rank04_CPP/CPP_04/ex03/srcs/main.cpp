/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:27:25 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/29 16:22:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "../includes/AMateria.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"

void standardTests()
{
	std::cout << "<====================== STANDARD TESTS ======================>" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;

	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;

	ICharacter* bob = new Character("bob");

	std::cout << std::endl << "\e[1m" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl << "\e[0m" << std::endl;

	//Test with other alloc
	tmp = src->createMateria("ice");
	bob->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("cure");
	bob->equip(tmp);
	std::cout << "\e[1m" << std::endl;
	bob->use(1, *me);
	bob->use(0, *me);
	std::cout << std::endl << "\e[0m" << std::endl;
	//
	
	delete bob;
	delete me;
	delete src;
	std::cout << std::endl;
	std::cout << "<==================================================================>" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

void	deepCopyTest()
{
	std::cout << "<====================== DEEP COPY TESTS ======================>" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	Character me = Character("me");
	
	std::cout << std::endl;
	std::cout << "My name is: " << me.getName();
	std::cout << std::endl;
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Begining of the scope --> {" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "[Init Character meCpy = me; and display is name:]";
		std::cout << std::endl;

		Character meCpy = me;
		std::cout << "My name is: " << meCpy.getName();
		std::cout << std::endl;
		
	}
	std::cout << std::endl;
	std::cout << "} <-- End of the scope" << std::endl;
	std::cout << std::endl;
	
	std::cout << std::endl;
	std::cout << "My name is: " << me.getName();
	std::cout << std::endl;
	
	std::cout << std::endl;
}

int main()
{
	standardTests();
	deepCopyTest();
	std::cout << "<==================================================================>" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	//check leaks on macos
	// system("leaks materia");
	return (0);
}