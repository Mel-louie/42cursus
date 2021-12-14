/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:29:36 by louielouie        #+#    #+#             */
/*   Updated: 2021/12/14 12:59:22 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <set>
#include <string>
#include <iterator>
#include <cstdlib>
#include "../includes/span.hpp"

int	main( void )
{
	std::cout << "<--- Example in the subject: --->" << std::endl;
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortestSpan: ";
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan: ";
	std::cout << sp.longestSpan() << std::endl << std::endl;

	std::cout << "<--- Trying to add another number in sp oject: --->" << std::endl;
	try
	{
		sp.addNumber(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "<--- Trying with an empty object: --->" << std::endl;
	Span empty(0);
	try
	{
		std::cout << "shortestSpan: ";
		std::cout << empty.shortestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "<--- Trying with just one number in the oject: --->" << std::endl;
	Span one(1);
	one.addNumber(42);
	one.displayNumber();
	try
	{
		std::cout << "shortestSpan: ";
		std::cout << one.shortestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	
	std::cout << std::endl << "<--- Trying with filling the object with a vector: --->" << std::endl;	
	
	std::vector<int> v;
	for (int i = 0; i != 20000; ++i) // fill the vector with 20000 random numbers,
		v.push_back( rand() % 2000 ); // between 0 and 1999
	
	Span bigSpan(20000); // this oject can contain 20000 numbers

	try
	{
		bigSpan.addvector(v); // add the vector of 20000nb in bigSpan
		std::cout << "shortestSpan: ";
		std::cout << bigSpan.shortestSpan() << std::endl;
		std::cout << "longestSpan: ";
		std::cout << bigSpan.longestSpan() << std::endl;
		std::cout << "Try to add one more number: ";
		bigSpan.addNumber(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	// bigSpan.displayNumber();
	
	return ( 0 );
}
