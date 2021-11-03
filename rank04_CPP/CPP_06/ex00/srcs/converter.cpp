/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:54:45 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/03 23:52:48 by user42           ###   ########.fr       */
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

void	printDouble( double value )
{
	std::cout << "double: ";
	std::cout << value;
	std::cout << std::endl;
}

int	floatPecision( char* str )
{
	int	ret = 0;
	int i = 0;

	if ( str[0] == '-' )
		i++;
	while ( i < (int)strlen( str ) && isdigit( str[i] ) != 0 && str[i] != '.' )
		i++;
	if ( str[i] == '.' )
	{
		i++;
		if ( isdigit( str[i] ) != 0 )
			ret = 0;
		while ( i < (int)strlen( str ) && isdigit( str[i] ) != 0 )
		{
			ret++;
			i++;
		}
	}
	
	return ( ret );
}

void	printFloat( double value, int precision )
{
	std::cout << "float: ";
	std::cout.precision( precision );
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout << static_cast<float>( value );
	std::cout << "f";
	std::cout << std::endl;
}
