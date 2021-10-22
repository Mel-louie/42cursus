/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:09:14 by user42            #+#    #+#             */
/*   Updated: 2021/10/20 12:56:32 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "replace.hpp"
#include <stdio.h>

int	main(int ac, char **av)
{
	if ( checkArgs( ac, av) )
		return (1);

	std::string	fileName = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	if ( openFile(fileName) == 1 )
	{
		std::cerr << "Error: unable to open " << fileName << "." << std::endl;
		return ( 1 );
	}
	std::string	content = getBuffer(fileName);

	std::ofstream	replaceFile;
	std::string	replaceFilename = "";
	replaceFilename = av[1];
	replaceFilename.append(".replace");
	replaceFile.open(replaceFilename.c_str(), std::ios::out | std::ios::app);
	if ( !replaceFile.is_open() )
	{
		std::cout << "Error: unable to open " << replaceFilename << "." << std::endl;
		return (1);
	}

	strReplace(content, s1, s2);
	replaceFile << content;
	replaceFile.close();

	return (0);
}
