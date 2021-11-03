/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:51:10 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/04 00:08:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "../includes/converter.hpp"

int	main( int ac, char **av )
{
	double	value;
	char*	end = NULL;

	if (ac != 2 )
	{
		displayUsage();
		return (1);
	}
	
	value = strtod( av[1], &end );

	if ( strlen(av[1]) == 1 && !isdigit(av[1][0]) )
	{
		printChar( static_cast<double>(av[1][0]) );
		printInt( static_cast<double>(av[1][0]) );
		printFloat( static_cast<double>(av[1][0]), 1 );
		printDouble( static_cast<double>(av[1][0]) );
	}
	else
	{
		printChar( value );
		printInt( value );
		printFloat( value, floatPecision( av[1]) );
		printDouble( value) ;
	}
	return (0);
}
