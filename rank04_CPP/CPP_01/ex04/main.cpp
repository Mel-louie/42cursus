/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:09:14 by user42            #+#    #+#             */
/*   Updated: 2021/10/18 19:17:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "replace.hpp"

void	strReplace(std::string& content, std::string s1, std::string s2)
{
	std::size_t	toErase = s1.length(); 
	std::size_t	newIndex = s2.length();
	std::size_t	position = content.find(s1);

	while (position != std::string::npos)
	{
		content.erase(position, toErase);
		content.insert(position, s2);
		position = content.find( s1, position + newIndex);
	}
}

int	main(int ac, char **av)
{
	if ( checkArgs( ac, av) )
		return (1);

	std::ofstream	replaceFile;
	std::string	replaceFilename = "";
	replaceFilename = av[1];
	replaceFilename.append(".replace");

	std::string	fileName = av[1];
	std::string	content = getBuffer(fileName);
	if (content == "\0")
	{
		std::cout << "Error: can't open the file." << std::endl;
		return (1);
	}
	std::string	s1 = av[2];
	std::string	s2 = av[3];


	replaceFile.open(replaceFilename.c_str(), std::ios::out | std::ios::app);
	if ( !replaceFile.is_open() )
	{
		std::cout << "Error: unable to open " << replaceFilename << "." << std::endl;
	}

	strReplace(content, s1, s2);

	replaceFile << content;
	replaceFile.close();
	

	return (0);
}
