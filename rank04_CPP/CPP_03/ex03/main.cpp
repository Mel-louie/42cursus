/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:51:13 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/26 15:02:54 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap	foo("Michel");
	FragTrap	bar("Roger");
	FragTrap	rndom(bar);

	std::cout << std::endl;

	std::cout << foo.getName() << " hits points: " << foo.getHitPoints() << std::endl;
	std::cout << foo.getName() << " energy points: " << foo.getEnergyPoints() << std::endl;
	std::cout << foo.getName() << " attack damages: " << foo.getAttackDamage() << std::endl;
	std::cout << std::endl;
	std::cout << rndom.getName() << " hits points: " << bar.getHitPoints() << std::endl;
	std::cout << rndom.getName() << " energy points: " << bar.getEnergyPoints() << std::endl;
	std::cout << rndom.getName() << " attack damages: " << bar.getAttackDamage() << std::endl;
	
	std::cout << std::endl;
	
	foo.attack(rndom.getName());
	rndom.takeDamage(bar.getAttackDamage());
	bar.attack(foo.getName());
	foo.takeDamage(bar.getAttackDamage());
	
	std::cout << std::endl;
	
	rndom.highFivesGuys();

	std::cout << std::endl;
	return (0);
}
