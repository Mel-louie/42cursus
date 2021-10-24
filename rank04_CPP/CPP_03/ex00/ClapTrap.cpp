/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:45:13 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/24 17:50:28 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	
	std::cout << "Default constructor has been called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name ): _name( name ) {
	
	std::cout << "Constructor has been called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const& src ): _name( src.getName() ) {
	
	std::cout << "Copy constructor has been called" << std::endl;
	return ;
}

ClapTrap::~ClapTrap() {
	
	std::cout << "Destructor has been called" << std::endl;
	return ;
}

ClapTrap&	ClapTrap::operator=( ClapTrap const& src) {
	
	std::cout << "Assigment operator has been called" << std::endl;
	this->_name = src.getName();
	return *this;
}

std::string	ClapTrap::getName( void ) const {
	
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints( void ) const {

	return (this->_hitPoints);	
}

unsigned int	ClapTrap::getEnergyPoints( void ) const {

	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage( void ) const {
	
	return (this->_attackDamage);
}

void	ClapTrap::attack( std::string const& target) {
	
	std::cout << "ClapTrap " << this->getName() << " attack " << target << " causing "
	<< this->getAttackDamage() << " points of damage." << std::endl;
	return ;
}

void	ClapTrap::takeDamage( unsigned int amount ) {

	std::cout << "ClapTrap " << this->getName() << " takes " << amount << " damages points!"
	<< std::endl;
	return ;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	
	std::cout << "ClapTrap " << this->getName() << " recovers " << amount << " energy points!!"
	<< std::endl;
	return ;
}
