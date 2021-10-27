/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:28:19 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/27 19:03:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

/*
 * CONSTRUCTORS
 */

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap(), _nameDiamond( "NAME" ) {

	std::cout << "DiamondTrap default constructor has been called" << std::endl;
	this->ClapTrap::_name.append("_clap_name");
	setHitPointsDiamond();
	setEnergyPointsDiamond();
	setAttackDamageDiamond();
	return ;
}

DiamondTrap::DiamondTrap( std::string name ): ClapTrap( name ), ScavTrap( name ), FragTrap( name ), _nameDiamond( name )  {
	
	std::cout << "DiamondTrap " << this->getName() << " constructor has been called" << std::endl;

	this->ClapTrap::_name.append("_clap_name");
	setHitPointsDiamond();
	setEnergyPointsDiamond();
	setAttackDamageDiamond();
	return ;
}

DiamondTrap::DiamondTrap( DiamondTrap const &src ) : ClapTrap( src ), ScavTrap( src ), FragTrap( src ) {

	std::cout << "DiamondTrap copy constructor has been called" << std::endl;

	this->_name = src.getName();
	this->ClapTrap::_name.append("_clap_name");
	setHitPointsDiamond();
	setEnergyPointsDiamond();
	setAttackDamageDiamond();
    return ;
}

/*
 * DESTRUCTORS
 */

DiamondTrap::~DiamondTrap() {

	std::cout << "DiamondTrap destructor has been called, " << this->getName() << " has been destroyed." << std::endl;
	return ;
}

/*
 * ASSIGMENT OPERATOR
 */

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& src) {

    FragTrap::operator=(src);
    ScavTrap::operator=(src);
    this->_nameDiamond = src.getNameDiamond();
    return (*this);
}

/*
 * GETTERS
 */

std::string	DiamondTrap::getNameDiamond() const {

	return (this->_nameDiamond);
}

unsigned int	DiamondTrap::getHitPointsDiamond( void ) {
	
	return (this->_hitPoints);
}

unsigned int	DiamondTrap::getEnergyPointsDiamond( void ) {
	
	return (this->_energyPoints);
}

unsigned int	DiamondTrap::getAttackDamageDiamond( void ) {

	return (this->_attackDamage);	
}

/*
 * SETTERS
 */

void	DiamondTrap::setHitPointsDiamond( void ) {
	
	this->FragTrap::setDefaultHitPoint();
	return ;
}

void	DiamondTrap::setEnergyPointsDiamond( void ) {
	
	this->ScavTrap::setDefaultEnergy();
	return ;
}

void	DiamondTrap::setAttackDamageDiamond( void ) {
	
	this->FragTrap::setDefaultAttackDamages();
	return ;
}

/*
 * MEMBER FUNCTIONS
 */

void	DiamondTrap::attack( std::string const& target ) {

	this->ScavTrap::attack( target );
	return ;
}

void	DiamondTrap::whoAmI() {

	std::cout << "My name is " << this->_nameDiamond << std::endl;
    std::cout << "My ClapTrap name is " << this->_name << std::endl;
	return ;
}
