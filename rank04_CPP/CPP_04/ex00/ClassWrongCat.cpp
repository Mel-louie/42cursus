/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassWrongWrongCat.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:54:36 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/27 19:31:40 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClassWrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
	
	std::cout << "WrongCat default constructor has been called" << std::endl;
	WrongAnimal::setType("WrongCat");
	return;
}

WrongCat::WrongCat( WrongCat const& cpy ) {
	
	std::cout << "WrongCat copy constructor has been called" << std::endl;
	this->_type = cpy.getType();
	return ;
}

WrongCat::~WrongCat() {

	std::cout << "WrongCat destructor has been called" << std::endl;
	return ;
}

WrongCat&	WrongCat::operator=( WrongCat const& src) {
	
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

void	WrongCat::makeSound( void ) const {

	std::cout << "\"MEEEEEEEEEOWWWWW\"" << std::endl;
	return ;
}
