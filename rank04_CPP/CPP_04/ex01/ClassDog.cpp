/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:16:47 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/27 18:43:27 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClassDog.hpp"

Dog::Dog(): Animal() {

	std::cout << "Dog default constructor has been called" << std::endl;
	Animal::setType("Dog");
	return ;
}

Dog::Dog( Dog const& cpy) {

	std::cout << "Dog copy constructor has been called" << std::endl;
	this->_type = cpy.getType();
	return ;
}

Dog::~Dog() {
	
	std::cout << "Dog destructor has been called" << std::endl;
	return ;
}

Dog&	Dog::operator=( Dog const& src) {
	
	std::cout << "Dog assigment operator has been called" << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

void	Dog::makeSound( void ) const {

	std::cout << "\"WAF WAF WAF\"" << std::endl;
	return ;
}
