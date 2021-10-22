/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:09:14 by user42            #+#    #+#             */
/*   Updated: 2021/10/20 12:44:53 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "replace.hpp"

void	displayUsages()
{
	std::cout << "The program takes a filename, which exists and for which you have the permissions, and two strings, which are NOT empty." 
	<< std::endl;
	std::cout << "Like this:" << std::endl
	<< "\t./replace [filename] [string1] [string2]" << std::endl;
}

int	checkArgs(int ac, char **av)
{
	int	ret = 0;

	if (ac != 4 || av[1][0] == '\0' || av[2][0] == '\0' || av[3][0] == '\0')
	{
		displayUsages();
		return ( ret = 1 );
	}

	return (ret);
}

int	openFile(std::string fileName)
{
	int	ret = 0;
	std::ofstream file( fileName, std::ios::in | std::ios::out);
	
	if ( !file )
		return ( ret = 1 );
	file.close();
	return ( ret );
}

std::string	getBuffer(std::string fileName)
{
	std::string	dest;
	std::ostringstream	buffer;
	std::ifstream	file( fileName );

	if ( file )
	{
		buffer << file.rdbuf();
		file.close();
		dest = buffer.str();
	}

	return ( dest );
}
