/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:30:35 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/26 19:19:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(): ClapTrap() {
	
	std::cout << "FragTrap default constructor has been called" << std::endl;
	
	this->setName( "FragTrap" );
	this->setHitPoints( 100 );
	this->setEnergyPoints( 100 );
	this->setAttackDamage( 30 );
	return ;
}

FragTrap::FragTrap( std::string name ): ClapTrap( name ) {
	
	std::cout << "FragTrap " << this->getName() << " constructor has been called" << std::endl;

	this->setHitPoints( 100 );
	this->setEnergyPoints( 100 );
	this->setAttackDamage( 30 );
	return ;
}

FragTrap::FragTrap( FragTrap const& src): ClapTrap ( src ) {

	std::cout << "FragTrap copy constructor has been called" << std::endl;

	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return ;
}

FragTrap::~FragTrap() {

	std::cout << "FragTrap destructor has been called, " << this->getName() << " has been destroyed." << std::endl;
	return ;
}

FragTrap&	FragTrap::operator=( FragTrap const& src ) {

	std::cout << "FragTrap assigment operator has been called" << std::endl;
	ClapTrap::operator=( src );
	return *this;
}

void	FragTrap::attack( std::string const& target) {
	
	std::cout << "FragTrap " << this->getName() << " attack " << target << " causing "
	<< this->getAttackDamage() << " points of damage." << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(void) {

	int i;
	
	std::cout << this->getName() << " says: HELLO CORRECTOR! Would you like to high five me?\n> YES: enter 1, NO: enter 0" << std::endl;
	std::cin >> i;

	if (i != 1)
		std::cout << "Oh. OK then :(" << std::endl;
	else if (i == 1)
		std::cout << "Yeah! HIGH FIVE ✋" << std::endl;
	return ;
}
