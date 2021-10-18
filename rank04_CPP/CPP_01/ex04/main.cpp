/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:09:14 by user42            #+#    #+#             */
/*   Updated: 2021/10/18 18:09:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "replace.hpp"

int	main(int ac, char **av)
{
	std::string	replaceFilename = "";
	if (checkArgs( ac, av, replaceFilename ))
		return (1);

//	std::cout << replaceFilename;

	std::string	fileName = av[1];
	std::string	content = getBuffer(fileName);
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	
	
//	std::cout << "bufbeg:\n" << content << "bufend." << std::endl;
	
//	if ()
	if ( content.find(s1) != std::string::npos )
		std::cout << s1 << std::endl;

	return (0);
}
