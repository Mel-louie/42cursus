/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:51:13 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/25 17:35:53 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	foo("Michel");
	ScavTrap	bar(foo);

	std::cout << "Copy of " << bar.getName() << " is now named ";
	bar.setName("MichelCopy");
	std::cout << bar.getName() << std::endl;
	std::cout << std::endl;
	
	ScavTrap	rndom("Jean");
	std::cout << std::endl;
	
	std::cout << foo.getName() << " energy points: " << foo.getEnergyPoints() << std::endl;
	std::cout << bar.getName() << " energy points: " << bar.getEnergyPoints() << std::endl;
	std::cout << rndom.getName() << " energy points: " << rndom.getEnergyPoints() << std::endl;
	std::cout << std::endl;
	
	foo.attack(rndom.getName());
	rndom.takeDamage(bar.getAttackDamage());
	bar.attack(rndom.getName());
	rndom.takeDamage(bar.getAttackDamage());
	std::cout << std::endl;
	
	rndom.guardGate();

	std::cout << std::endl;
	return (0);
}
