/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:58:41 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/11 15:23:16 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main( void )
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << std::endl << "Display the adress of the string" << std::endl
	<< "\t- by using &string   : " << &string << std::endl
	<< "\t- by using stringPTR : " << stringPTR << std::endl
	<< "\t- by using &stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << std::endl << "Display the string" << std::endl
	<< "\t- by using the pointer:  *stringPTR: " << *stringPTR << std::endl
	<< "\t- by using the reference: stringREF: " << stringREF << std::endl;

	std::cout << std::endl;
	return (0);
}