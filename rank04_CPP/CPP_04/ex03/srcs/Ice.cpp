/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 09:56:30 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/29 11:06:37 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"

Ice::Ice( void ): AMateria( "ice" ) {

	std::cout << "Ice default constructor has been called" << std::endl;
	return ;
}

Ice::Ice( Ice const& cpy ): AMateria( cpy._type ) {
	
	std::cout << "Ice copy constructor has been called" << std::endl;
	return ;
}

Ice::Ice( std::string const& type ): AMateria( type ) {

	std::cout << "Ice parametrized constructor has been called" << std::endl;
	return ;
}

Ice::~Ice( void ) {

	std::cout << "Ice destructor has been called" << std::endl;
	return ;
}

Ice&	Ice::operator=( Ice const& src ) {
	
	if (this != &src)
		this->_type = src.getType();
	return ( *this );
}

AMateria*	Ice::clone( void ) const {

	AMateria	*ptr = new Ice( this->_type );
	return ( ptr );
}

void	Ice::use( ICharacter& target ) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
