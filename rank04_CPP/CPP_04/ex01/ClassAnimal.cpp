/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:32:43 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/27 18:41:41 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassAnimal.hpp"

Animal::Animal(): _type( "Animal" ) {
	
	std::cout << "Animal default constructor has been called" << std::endl;
	return ;
}

Animal::Animal( Animal const& cpy ) {
	
	std::cout << "Animal copy constructor has been called" << std::endl;
	this->_type = cpy.getType();
	return ;
}

Animal::~Animal() {
	
	std::cout << "Animal destructor has been called" << std::endl;
	return ;
}

Animal&	Animal::operator=( Animal const& src ) {

	std::cout << "Animal assigment operator has been called" << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

void	Animal::setType( std::string const& type ) {

	this->_type = type;
	return ;
}

std::string	Animal::getType( void ) const {
	
	return ( this->_type );
}

void	Animal::makeSound( void ) const {
	
	std::cout << "* weird noise, definitly from an animal *" << std::endl;
	return ;
}
