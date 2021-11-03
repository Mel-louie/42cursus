/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:26:54 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/03 14:02:09 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "../includes/iter.hpp"

void	printIntArr( int &i )
{
	std::cout << i << " "; 
}

void	plusOne( int &i )
{
	std::cout << i + 1 << " ";
}

void	arrLen( char &c )
{
	std::cout << c; 
}

void	upper(char &c) {

	c = toupper(c);
	std::cout << c;
	return ;
}

int	main( void )
{
	int	arrInt[] = {0, 1, 2, 3};
	char	string[] = "hello world!";
	
	std::cout << "Print array of ints:\t\t\t";
	::iter( arrInt, 4, printIntArr );
	std::cout << std::endl;
	
	std::cout << "Array of ints +1 to every digits:\t";
	::iter( arrInt, 4, plusOne );
	std::cout << std::endl;

	std::cout << "Print array of chars:\t\t";
	::iter( string, strlen( string ), arrLen );
	std::cout << std::endl;

	std::cout << "Print array of chars toUpper:\t";
	::iter( string, strlen( string ), upper );
	std::cout << std::endl;
	
	std::cout << std::endl;
	std::cout << "<--- Test with template function (template<typename T>void plusTen( T& t)) --->" << std::endl;
	std::cout << "Array of int:" << std::endl;
	::iter( arrInt, 4, ::plusTen );
	std::cout << std::endl;
	std::cout << "Array of char (ascii code):" << std::endl;
	::iter( string, strlen( string ), ::plusTen );
	std::cout << std::endl;
	
	return (0);
}
