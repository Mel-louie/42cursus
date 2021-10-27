/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:51:13 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/27 19:15:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main()
{
	DiamondTrap	foo("Michel");
	DiamondTrap	bar(foo);
	
	std::cout << std::endl;

	bar.setName("Jean");
	std::cout << "Michel copy is now named: " << bar.getName() << std::endl;
	std::cout << std::endl;

	std::cout << foo.getNameDiamond() << " hits points: " << foo.getHitPointsDiamond() << std::endl;
	std::cout << foo.getNameDiamond() << " energy points: " << foo.getEnergyPointsDiamond() << std::endl;
	std::cout << foo.getNameDiamond() << " attack damages: " << foo.getAttackDamageDiamond() << std::endl;
	std::cout << bar.getName() << " hits points: " << bar.getHitPointsDiamond() << std::endl;
	std::cout << bar.getName() << " energy points: " << bar.getEnergyPointsDiamond() << std::endl;
	std::cout << bar.getName() << " attack damages: " << bar.getAttackDamageDiamond() << std::endl;
	std::cout << std::endl;

	foo.attack(bar.getNameDiamond());
	std::cout << std::endl;

	std::cout << "\tWho are you?" << std::endl;
	foo.whoAmI();
	std::cout << std::endl;

	foo.highFivesGuys();
	std::cout << std::endl;

	foo.guardGate();
	std::cout << std::endl;
	
	return (0);
}
