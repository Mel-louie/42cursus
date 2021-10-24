/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:51:13 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/24 20:42:08 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	Clap;
	ClapTrap	Trap(Clap);
	std::string	nameClap = "Jean";
	std::string	nameTrap = "Michel";
	
	std::cout << std::endl;
	std::cout << "ClapTrap Jean and ClapTrap Michel are on the ring." << std::endl;
	

	Clap.setName(nameClap);
	Trap.setName(nameTrap);
	std::cout << std::endl;

	Clap.attack(Trap.getName());
	Trap.takeDamage(0);
	std::cout << std::endl;
	Clap.takeDamage(30);
	Clap.takeDamage(10);
	std::cout << Clap.getName() << " is hurt." << std::endl;
	std::cout << std::endl;
	Clap.beRepaired(10);
	Clap.takeDamage(10);
	Clap.beRepaired(0);
	Clap.attack(Trap.getName());
	std::cout << std::endl;
	std::cout << Trap.getName() << " WINS" << std::endl;
	
	return (0);	
}
