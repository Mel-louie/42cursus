/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:35:26 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/11 14:53:31 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int	n;
	Zombie	*Horde;

	std::cout << "How many zombies do you want?\n> ";
	std::cin >> n; 
	
	Horde = zombieHorde(n, "oneOfMany");
	
	int	i = -1;

	while (++i < n)
	{
		std::cout << "Zombie number " << i + 1 << ": ";
		Horde[i].announce();
	}

	delete [] Horde;
	
	return (0);
}
