/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:26:54 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/04 11:34:28 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "../includes/iter.hpp"

class Basic
{
private:
	int _nb;
public:
	Basic(void) : _nb( 1000 ) { return ; }
	int getNb(void) const { return this->_nb; }
};

std::ostream & operator<<(std::ostream & o, const Basic& rhs)
{
	o << rhs.getNb();
	return o;
}

void	plusOne( int &i )
{
	std::cout << i + 1 << " ";
}

void	upper(char &c) {

	c = toupper(c);
	std::cout << c << " ";
	return ;
}

int	main( void )
{
	int	arrInt[] = {0, 1, 2, 3};
	char	string[] = "hello world!";
	
	std::cout << "Print array of ints:\t\t\t";
	::iter( arrInt, 4, printElem );
	std::cout << std::endl;
	
	std::cout << "Array of ints +1 to every digits:\t";
	::iter( arrInt, 4, plusOne );
	std::cout << std::endl;

	std::cout << "Print array of chars:\t\t";
	::iter( string, strlen( string ), printElem );
	std::cout << std::endl;

	std::cout << "Print array of chars toUpper:\t";
	::iter( string, strlen( string ), upper );
	std::cout << std::endl;
	
	std::cout << std::endl;
	std::cout << "<--- Test with template function (template<typename T>void plusTen( T& t)) --->" << std::endl;
	std::cout << "Array of int:" << std::endl;
	::iter( arrInt, 4, ::plusTen );
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "<--- Test with an array in a class --->" << std::endl;
	std::cout << "arrayClass[5], fill with 1000:" << std::endl;
	Basic arrayClass[5];

	iter(arrayClass, 5, printElem);
	std::cout << std::endl;
	
	return (0);
}
