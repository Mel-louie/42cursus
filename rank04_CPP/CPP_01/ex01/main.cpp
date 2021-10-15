/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:35:26 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/15 17:26:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int	i = -1;
	int	n;

	std::cout << "Hello! How many Zombies do you want?\n> ";
	std::cin >> n;
	std::cout << std::endl;
	
	Zombie*	horde = zombieHorde(n, "oneOfThousands");

	while (++i < n)
		horde[i].announce();

	std::cout << std::endl;
	std::cout << "Oh no! You create to many Zombies! Kill them all!" << std::endl;
	std::cout << std::endl;

	delete [] horde;
	return (0);
}
