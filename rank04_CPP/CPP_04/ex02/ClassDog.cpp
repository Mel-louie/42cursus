/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:16:47 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/28 15:47:36 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClassDog.hpp"

Dog::Dog(): AAnimal(), _brain( new Brain("i like bones!") ) {

	std::cout << "Dog default constructor has been called" << std::endl;
	AAnimal::setType("Dog");
	return ;
}

Dog::Dog( Dog const& cpy) {

	std::cout << "Dog copy constructor has been called" << std::endl;
	this->_type = cpy.getType();
	this->_brain = new Brain(*cpy._brain);
	return ;
}

Dog::~Dog() {
	
	std::cout << "Dog destructor has been called" << std::endl;
	delete this->_brain;
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

void	Dog::setBrain( Brain& brain) {

	delete this->_brain;

	this->_brain = new Brain(brain);
	return ;
}

Brain*	Dog::getBrain( void ) const {
	
	return (this->_brain);
}

