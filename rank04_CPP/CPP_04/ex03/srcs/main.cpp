/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:27:25 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/29 13:18:06 by louielouie       ###   ########.fr       */
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

int main()
{
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

	//check leaks on macos
	system("leaks materia");
	
	return (0);
}