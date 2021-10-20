/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:02:16 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/18 15:02:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB( void ): _name("JeanMarc"), _weapon()
{
	
}

HumanB::HumanB( const std::string& name ): _name(name), _weapon()
{
	
}

HumanB::~HumanB()
{
	
}

//setters
void	HumanB::setWeapon( Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::setName( const std::string name)
{
	this->_name = name;
}

//getters
const Weapon*	HumanB::getWeapon( void ) const
{
	return (this->_weapon);
}

std::string	HumanB::getName( void ) const
{
	return (this->_name);
}

void	HumanB::attack( void )
{
	if (_weapon == NULL)
		std::cout << this->getName() << " attacks without weapon!!" << std::endl;
	else
		std::cout << this->getName() << " attacks with his " << this->getWeapon()->getType() << std::endl;
}
