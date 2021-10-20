/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:02:16 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/18 14:41:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA( Weapon& weapon): _name("JeanMi"), _weapon(weapon)
{
	
}

HumanA::HumanA( const std::string& name, Weapon& weapon ): _name(name), _weapon(weapon)
{
	
}

HumanA::~HumanA()
{
	
}

//setters
void	HumanA::setWeapon( const Weapon& weapon)
{
	this->_weapon = weapon;
}

void	HumanA::setName( const std::string name )
{
	this->_name = name;
}

//getters
std::string	HumanA::getName( void ) const
{
	return (this->_name);
}

const Weapon& HumanA::getWeapon( void ) const
{
	return (this->_weapon);
}

void	HumanA::attack( void )
{
	std::cout << this->getName() << " attacks with his " << this->getWeapon().getType() << std::endl;
}
