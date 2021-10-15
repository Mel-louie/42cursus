/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:51:34 by user42            #+#    #+#             */
/*   Updated: 2021/10/15 15:07:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( std::string name ): _name(name)
{

}

Zombie::~Zombie( void )
{
	std::cout << Zombie::getName() << " is dead for good" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << Zombie::getName() << " BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName( void )
{
	return (_name);
}	
