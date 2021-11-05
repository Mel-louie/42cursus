/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:29:36 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/05 15:47:06 by louielouie       ###   ########.fr       */
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
#include <ctime>
#include "../includes/span.hpp"

int	main( void )
{	
	srand ( time(NULL) );
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::vector<int> v;
	Span test(20000);
	try
	{
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	for (int i = 0; i != 10000; ++i)
		v.push_back( rand()%20000000) ;
	try
	{
		test.addNumber<std::vector<int>::iterator>(v.begin(), v.end());
		test.addNumber<std::vector<int>::iterator>(v.begin(), v.end());
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
		test.addNumber(2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return ( 0 );
}
