/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:03:04 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/29 12:52:57 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Character.hpp"

Character::Character( void ): _matMax(4), _name( "RandomPeon" ), _inventory() {

	std::cout << "Character default constructor has been called" << std::endl;
	int	i = -1;
	
	while (++i < _matMax)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character( Character const& cpy): _matMax(4), _name(cpy._name), _inventory() {

	std::cout << "Character copy constructor has been called" << std::endl;
	int	i = -1;
	
	while (++i < _matMax)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character( std::string const& name ): _matMax(4), _name( name ), _inventory() {

	std::cout << "Character parametrized constructor has been called" << std::endl;
	int	i = -1;
	
	while (++i < _matMax)
		this->_inventory[i] = NULL;
	return ;
}

Character::~Character( void ) {

	std::cout << "Character destructor has been called" << std::endl;
	int	i = -1;

	while (++i < _matMax)
		if ( this->_inventory[i] != NULL )
			delete ( this->_inventory[i] );
	
	//delete [] this->_inventory;
	return ;
}

Character	&Character::operator=( Character const& src ) {

	if ( this != &src)
	{
		this->_name = src.getName();
		
		for (int i = 0; i < _matMax; i++)
		{
			if (src._inventory[i] != NULL)
			{
				if (this->_inventory[i] != NULL)
				{
					delete (this->_inventory[i]);
					this->_inventory[i] = NULL;
				}
				this->_inventory[i] = src._inventory[i]->clone();
			}
			else
			{
				if (this->_inventory[i] != NULL)
				{
					delete (this->_inventory[i]);
					this->_inventory[i] = NULL;
				}
			}
		}
	}
	return ( *this );
}

std::string const&	Character::getName( void ) const {

	return ( this->_name );
}

void	Character::equip(AMateria *m) {

	if (!m)
		return ;

	int	i = 0;

	while ( i < _matMax && ( this->_inventory[i] != NULL ) )
		i++;

	if ( i < _matMax )
		this->_inventory[i] = m;
	
	return ;
}

void	Character::unequip(int idx) {

	this->_inventory[idx] = NULL;
	return ;
}

void	Character::use(int idx, ICharacter &target) {

	if ( idx >= 0 && idx < _matMax && this->_inventory[idx] != NULL )
	{
		this->_inventory[idx]->use( target );
		delete ( this->_inventory[idx] );
		this->_inventory[idx] = NULL;
	}
	return ;
}
