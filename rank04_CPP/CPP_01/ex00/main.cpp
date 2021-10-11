/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:35:26 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/11 14:17:19 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*zombie;
	Zombie	*mortVivant;
	
	zombie = newZombie("Alfred");
	zombie->announce();
	//free the memory of the dynamic allocation
	delete zombie;

	mortVivant = newZombie("Antoine");
	mortVivant->announce();
	//free the memory of the dynamic allocation
	delete mortVivant;
	
	randomChump("John");
	randomChump("Mario");
	
	return (0);
}
