/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:15:45 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/29 11:21:54 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"

Cure::Cure( void ): AMateria ( "cure" ) {

	std::cout << "Cure default constructor has been called" << std::endl;
	return ;
}

Cure::Cure( Cure const& cpy ): AMateria( cpy._type ) {
	
	std::cout << "Cure copy constructor has been called" << std::endl;
	return ;
}


Cure::Cure( std::string const& type ): AMateria( type ) {

	std::cout << "Cure parametrized constructor has been called" << std::endl;
	return ;
}

Cure::~Cure( void ) {
	
	std::cout << "Cure destructor has been called" << std::endl;
	return ;
}

Cure&	Cure::operator=( Cure const& src ) {

	if (this != &src)
		this->_type = src.getType();
	return ( *this );
}

AMateria*	Cure::clone( void ) const {

	AMateria	*ptr = new Cure(this->_type);
	return ( ptr );
}

void	Cure::use( ICharacter& target ) {

	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
	return ;
}
