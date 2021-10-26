/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:28:19 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/26 16:52:34 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap(), _nameDiamond("DIAMOND_NAME") {

	std::cout << "DiamondTrap default constructor has been called" << std::endl;
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_attackDamage = FragTrap::getAttackDamage();
	return ;
}

DiamondTrap::DiamondTrap( std::string name ): ClapTrap( name ), ScavTrap( name ), FragTrap( name ), _nameDiamond( name )  {
	
	std::cout << "DiamondTrap " << this->getName() << " constructor has been called" << std::endl;

	this->ClapTrap::_name.append("_clap_name");
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_attackDamage = FragTrap::getAttackDamage();
	return ;
}

DiamondTrap::DiamondTrap( DiamondTrap const &src ) : ClapTrap( src ), ScavTrap( src ), FragTrap( src ) {

	std::cout << "DiamondTrap copy constructor has been called" << std::endl;

	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
    return ;
}

DiamondTrap::~DiamondTrap() {

	std::cout << "DiamondTrap destructor has been called, " << this->getName() << " has been destroyed." << std::endl;
	return ;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& src) {

    FragTrap::operator=(src);
    ScavTrap::operator=(src);
    this->_nameDiamond = src.getNameDiamond();
    return (*this);
}

std::string	DiamondTrap::getNameDiamond() const {

	return (this->_nameDiamond);
}

void	DiamondTrap::whoAmI() {

	std::cout << "My name is " << this->_nameDiamond << std::endl;
    std::cout << "My ClapTrap name is " << this->_name << std::endl;
	return ;
}

void	DiamondTrap::attack( std::string const& target ) {

	this->ScavTrap::attack( target );
	return ;
}
