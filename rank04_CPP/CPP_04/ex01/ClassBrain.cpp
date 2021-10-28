/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBrain.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:20:23 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/28 14:39:45 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassBrain.hpp"

Brain::Brain() {
	
	std::cout << "Brain default constructor has been called" << std::endl;
	
	setIdeas("Am hungry...");
	return ;
}

Brain::Brain( Brain const& cpy ) {

	std::cout << "Brain copy constructor has been called" << std::endl;
	*this = cpy;
	return ;
}

Brain::Brain( std::string const& ideas ) {
	
	std::cout << "Brain parameterized constructor has been called" << std::endl;

	setIdeas( ideas );
	return ;
}

Brain::~Brain() {

	std::cout << "Brain destructor has been called" << std::endl;
	return ;
}

Brain&	Brain::operator=( Brain const& src ) {
	
	if (this != &src)
		setIdeas(src._ideas[0]);
	return (*this);
}

void	Brain::setIdeas( std::string const& ideas ) {
	
	int	i = -1;
	int maxIdeas = 100;
	
	while (++i < maxIdeas)
		this->_ideas[i] = ideas;
	return ;
}

void	Brain::displayIdeas( void ) {

	int	i = -1;
	int maxIdeas = 100;
	
	while (++i < maxIdeas)
		std::cout << _ideas[i] << " ";
	return ;
}
