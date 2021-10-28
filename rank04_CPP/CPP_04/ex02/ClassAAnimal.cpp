/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassAAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:32:43 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/27 18:41:41 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassAAnimal.hpp"

AAnimal::AAnimal(): _type( "AAnimal" ) {
	
	std::cout << "AAnimal default constructor has been called" << std::endl;
	return ;
}

AAnimal::AAnimal( AAnimal const& cpy ) {
	
	std::cout << "AAnimal copy constructor has been called" << std::endl;
	this->_type = cpy.getType();
	return ;
}

AAnimal::~AAnimal() {
	
	std::cout << "AAnimal destructor has been called" << std::endl;
	return ;
}

AAnimal&	AAnimal::operator=( AAnimal const& src ) {

	std::cout << "AAnimal assigment operator has been called" << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

void	AAnimal::setType( std::string const& type ) {

	this->_type = type;
	return ;
}

std::string	AAnimal::getType( void ) const {
	
	return ( this->_type );
}

void	AAnimal::makeSound( void ) const {
	
	std::cout << "* weird noise, definitly from an AAnimal *" << std::endl;
	return ;
}
