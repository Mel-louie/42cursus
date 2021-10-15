/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:51:34 by user42            #+#    #+#             */
/*   Updated: 2021/10/15 15:48:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main( void )
{
	Zombie*	zombie1 = newZombie("zombieOnTheHeap");
	std::string	zombie2 = "zombieOnTheStack";

	zombie1->announce();
	randomChump(zombie2);

	delete zombie1;
	return (0);
}
