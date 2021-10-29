/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:40:41 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/28 23:27:08 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria( void ): _type( "default" ) {

	std::cout << "AMateria default constructor has been called" << std::endl;
	return ;
}

AMateria::AMateria( AMateria const& cpy ): _type(cpy._type) {
	
	std::cout << "AMateria copy constructor has been called" << std::endl;
	return ;
}

AMateria::AMateria( std::string const& type ): _type( type ) {

	std::cout << "AMateria parametrized constructor has been called" << std::endl;
	return ;
}

AMateria::~AMateria( void ) {
	
	std::cout << "AMateria destructor has been called" << std::endl;
	return ;
}

AMateria&	AMateria::operator=( AMateria const& src ) {

	if ( this != &src )
		this->_type = src.getType();
	return ( *this );
}

std::string const&	AMateria::getType( void ) const {
	
	return ( this->_type );
}

void	AMateria::use( ICharacter& target ) {

	if (this->_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (this->_type == "cure")
		std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
	else
		std::cout << "* unknown Materia *" << std::endl;
}
