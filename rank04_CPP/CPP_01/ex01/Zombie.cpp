/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:00:16 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/15 15:54:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	
}

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

void	Zombie::setName( std::string name)
{
	this->_name = name;
}

std::string	Zombie::getName( void )
{
	return (_name);
}	
