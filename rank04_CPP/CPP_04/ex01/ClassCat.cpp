/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:54:36 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/28 14:42:03 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClassCat.hpp"

Cat::Cat(): Animal(), _brain( new Brain("Nyanyanyanyanyanyanya!") ) {
	
	std::cout << "Cat default constructor has been called" << std::endl;
	Animal::setType("Cat");
	return;
}

Cat::Cat( Cat const& cpy ) {
	
	std::cout << "Cat copy constructor has been called" << std::endl;
	this->_type = cpy.getType();
	this->_brain = new Brain(*cpy._brain);
	return ;
}

Cat::~Cat() {

	std::cout << "Cat destructor has been called" << std::endl;
	delete this->_brain;
	return ;
}

Cat&	Cat::operator=( Cat const& src) {
	
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

void	Cat::makeSound( void ) const {

	std::cout << "\"MEEEEEEEEEOWWWWW\"" << std::endl;
	return ;
}

void	Cat::setBrain( Brain& brain) {

	delete this->_brain;

	this->_brain = new Brain(brain);
	return ;
}

Brain*	Cat::getBrain( void ) const {
	
	return (this->_brain);
}
