/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:35:26 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/20 12:41:45 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av)
{
	int	i = -1;
	int	n = 0;

	if (ac != 1)
	{
		std::cout << "You don't need args" << std::endl;
		return (1);
		(void)av;
	}

	std::cout << "Hello! How many Zombies do you want?\n> ";
	while (!(std::cin >> n))
	{
		std::cout << "Must be a number, between 1 and INT_MAX";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << std::endl;
		std::cout << "> ";
	}
	std::cout << std::endl;
	
	if (n <= 0)
	{
		std::cout << "Number of Zombies must be positive" << std::endl;
		return (1);
	}
	
	Zombie*	horde = zombieHorde(n, "oneOfThousands");

	while (++i < n)
		horde[i].announce();

	std::cout << std::endl;
	std::cout << "Oh no! You create to many Zombies! Kill them all!" << std::endl;
	std::cout << std::endl;

	delete [] horde;
	return (0);
}
