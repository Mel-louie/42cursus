/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:12:41 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/18 14:01:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

//default constructor
Weapon::Weapon()
{
	
}

Weapon::Weapon( const std::string& type ): _type(type)
{
	
}

Weapon::~Weapon()
{
	
}

void	Weapon::setType( const std::string& type)
{
	this->_type = type;
}

const std::string&	Weapon::getType( void ) const
{
	return (this->_type);
}
