/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:00:16 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/11 14:49:26 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


//constructors
Zombie::Zombie(void): _name("louie") {}

Zombie::Zombie(std::string name): _name(name) {}


//destructor
Zombie::~Zombie(void)
{
	std::cout << "Zombie "<< this->getName() << " has been killed!" << std::endl;
}


std::string	Zombie::getName( void )
{
	return (_name);	
}

void	Zombie::setName(std::string str)
{
	this->_name = str;
	return ;
}


void	Zombie::announce( void )
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
