/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:45:13 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/25 16:52:43 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name( "NAME" ), _hitPoints(10), _energyPoints(10),
_attackDamage(0) {
	
	std::cout << "ClapTrap default constructor has been called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name ): _name( name ), _hitPoints(10), _energyPoints(10),
_attackDamage(0) {
	
	std::cout << "ClapTrap " << this->getName() << " constructor has been called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const& src ): _name(src._name), _hitPoints(src._hitPoints),
	_energyPoints(src._energyPoints), _attackDamage(src._attackDamage) {
	
	std::cout << "ClapTrap copy constructor has been called" << std::endl;
	return ;
}

ClapTrap::~ClapTrap() {
	
	std::cout << "ClapTrap destructor has been called, " << this->getName() 
	<< " has been destroyed." << std::endl;
	return ;
}

ClapTrap&	ClapTrap::operator=( ClapTrap const& src) {
	
	std::cout << "ClapTrap assigment operator has been called" << std::endl;
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
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

void	ClapTrap::setName( std::string name ) {

	this->_name = name;
	return ;
}

void	ClapTrap::setHitPoints( unsigned int hitPoints ) {

	this->_hitPoints = hitPoints;
	return ;
}

void	ClapTrap::setEnergyPoints( unsigned int energyPoints ) {

	this->_energyPoints = energyPoints;
	return ;
}

void	ClapTrap::setAttackDamage( unsigned int attackDamage ) {

	this->_attackDamage = attackDamage;
	return ;
}
