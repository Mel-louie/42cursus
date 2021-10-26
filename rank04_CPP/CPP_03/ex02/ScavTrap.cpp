/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:37:05 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/25 17:15:49 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {

	std::cout << "ScavTrap default constructor has been called" << std::endl;

	this->setName( "ScavTrap" );
	this->setHitPoints( 100 );
	this->setEnergyPoints( 50 );
	this->setAttackDamage( 20 );
	return ;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap( name ) {

	std::cout << "ScavTrap " << this->getName() << " constructor has been called" << std::endl;

	this->setHitPoints( 100 );
	this->setEnergyPoints( 50 );
	this->setAttackDamage( 20 );
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
	
	std::cout << "ScavTrap " << this->getName() << " attack " << target << " causing "
	<< this->getAttackDamage() << " points of damage." << std::endl;
	return ;
}

void	ScavTrap::guardGate() {

	std::cout << "ScavTrap " << this->getName() << " is now THE KEEPER OF THE GATE!1!!"<< std::endl;	
	return ;
}
