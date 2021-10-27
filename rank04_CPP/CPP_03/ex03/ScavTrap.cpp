/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:37:05 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/27 19:10:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {

	std::cout << "ScavTrap default constructor has been called" << std::endl;

	this->setName( "NAME" );
	this->setDefaultHitPoint(  );
	this->setDefaultEnergy(  );
	this->setDefaultAttackDamages(  );
	return ;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap( name ) {

	std::cout << "ScavTrap " << this->getName() << " constructor has been called" << std::endl;

	this->setDefaultHitPoint(  );
	this->setDefaultEnergy(  );
	this->setDefaultAttackDamages(  );
	return ;
}

ScavTrap::ScavTrap( ScavTrap const& src): ClapTrap( src ) {

	std::cout << "ScavTrap copy constructor has been called" << std::endl;

	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return ;
}

ScavTrap::~ScavTrap() {

	std::cout << "ScavTrap destructor has been called, " << this->getName() 
	<< " has been destroyed." << std::endl;
	return ;
}

ScavTrap&	ScavTrap::operator=( ScavTrap const& src ) {

	std::cout << "ScavTrap assigment operator has been called" << std::endl;
	ClapTrap::operator=( src );
	return *this;
}

void	ScavTrap::attack( std::string const& target) {
	
	std::cout << this->getName() << " [ScavTrap-attack]" << target << " causing "
	<< this->getAttackDamage() << " points of damage." << std::endl;
	return ;
}

void	ScavTrap::guardGate() {

	std::cout << this->getName() << " is now THE KEEPER OF THE GATE!1!!"<< std::endl;	
	return ;
}

void	ScavTrap::setDefaultEnergy() {
	
	this->_energyPoints = 50;
	return ;
}

void	ScavTrap::setDefaultHitPoint() {
	
	this->_hitPoints = 100;
	return ;
}

void	ScavTrap::setDefaultAttackDamages() {

	this->_attackDamage = 20;
	return ;
}
