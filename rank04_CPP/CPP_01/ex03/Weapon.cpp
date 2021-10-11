/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:12:41 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/11 16:22:35 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string  weapon_type)
{
	this->_type = weapon_type;
	return ;
}

Weapon::~Weapon() {}

const std::string&	Weapon::getType( void ) const
{
	return (this->_type);
}

void	Weapon::setType(const std::string& _type)
{
   this->_type = _type;
}
