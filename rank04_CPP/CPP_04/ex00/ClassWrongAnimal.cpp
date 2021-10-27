/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:32:43 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/27 18:41:41 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassWrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type( "WrongAnimal" ) {
	
	std::cout << "WrongAnimal default constructor has been called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( WrongAnimal const& cpy ) {
	
	std::cout << "WrongAnimal copy constructor has been called" << std::endl;
	this->_type = cpy.getType();
	return ;
}

WrongAnimal::~WrongAnimal() {
	
	std::cout << "WrongAnimal destructor has been called" << std::endl;
	return ;
}

WrongAnimal&	WrongAnimal::operator=( WrongAnimal const& src ) {

	std::cout << "WrongAnimal assigment operator has been called" << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

void	WrongAnimal::setType( std::string const& type ) {

	this->_type = type;
	return ;
}

std::string	WrongAnimal::getType( void ) const {
	
	return ( this->_type );
}

void	WrongAnimal::makeSound( void ) const {
	
	std::cout << "* weird noise, definitly from an WrongAnimal *" << std::endl;
	return ;
}
