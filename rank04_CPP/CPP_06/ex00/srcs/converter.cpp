/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:54:45 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/02 16:03:52 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/converter.hpp"

void	printChar( double value )
{
	std::cout << "char: ";
	if ( value < CHAR_MIN || value > CHAR_MAX || std::isnan( value ) == true )
		std::cout << "impossible";
	else if (std::isprint( value ) == false )
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>( value ) << "'";
	std::cout << std::endl;
}


void	printInt( double value )
{
	std::cout << "int: ";
	if ( value < INT_MIN || value > INT_MAX || std::isnan( value ) == true)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>( value );
	std::cout << std::endl;
}
