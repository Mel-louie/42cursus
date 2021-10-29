/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 09:56:30 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/29 09:59:47 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"

Ice::Ice( void ): AMateria( "ice" ) {

	std::cout << "Ice default constructor has been called" << std::endl;
	return ;
}

Ice::Ice( Ice const& cpy ): AMateria( cpy._type ) {
	
	std::cout << "Ice copy constructor has been called" << std::endl;
	return ;
}


