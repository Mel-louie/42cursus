/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:09:14 by user42            #+#    #+#             */
/*   Updated: 2021/10/18 17:47:28 by user42           ###   ########.fr       */
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

	std::string	content;
	std::string	fileName = av[1];
	content = getBuffer(fileName);
	
//	std::cout << "bufbeg:\n" << content << "bufend." << std::endl;
	
	

	return (0);
}
