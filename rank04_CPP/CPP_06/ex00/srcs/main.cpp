/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:51:10 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/02 16:09:51 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
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
	// std::cout << value << std::endl;
	// std::cout << end << std::endl;
	if ( checkLitteraleValue(end) )
	{
		std::cout << "error: the programm needs a literal value. Example: '42.0f'" << std::endl;
		return (1);
	}

	if ( strlen(av[1]) == 1 && !isdigit(av[1][0]) )
	{
		printChar(static_cast<double>(av[1][0]));
		printInt(static_cast<double>(av[1][0]));
	// 	printFloat(static_cast<double>(av[1][0]), 1);
	// 	printDouble(static_cast<double>(av[1][0]));
	}
	else
	{
		printChar(value);
		printInt(value);
	// 	printFloat(value, get_Pecision(av[1]));
	// 	printDouble(value);
	}
	return (0);
}
