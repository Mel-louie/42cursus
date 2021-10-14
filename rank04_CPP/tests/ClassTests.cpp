/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:34:25 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/14 13:35:41 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassTests.hpp"

Sample::Sample( void )
{
	std::cout << "constructor called" << std::endl;

	this->_val = 42;
	std::cout << "this->_val\t: " << this->_val << std::endl;
	return ;
}

Sample::~Sample( void )
{
	std::cout << "destructor called" << std::endl;
	return ;
}

void	Sample::setVal(int val)
{
	if (val >= 0)
		this->_val = val;
	else
		std::cout << "The value must be > 0" << std::endl;
}

int	Sample::getVal( void ) const
{
	//getVal est une const, donc ne peut modifier les attribus, ceci ne complie pas :
	//this->_val = 222;
	return (this->_val);
}

void    Sample::bliblou( void )
{
	std::cout << "bliblou blip blop" << std::endl;
	return ;
}
