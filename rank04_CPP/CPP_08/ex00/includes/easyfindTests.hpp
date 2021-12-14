/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfindTests.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:07:56 by louielouie        #+#    #+#             */
/*   Updated: 2021/12/14 12:59:22 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFINDTESTS_HPP
# define EASYFINDTESTS_HPP

# include <iostream>
# include <deque>
# include <list>
# include <vector>
# include <set>
# include <string>
# include <iterator>
# include <cstdlib>
# include <ctime>

int	randomNum( void )
{
	srand(time (NULL));
	return ( rand() % 100 );
}

template<typename T>
void	displayContainer( const T& container )
{
	typename T::const_iterator	it;
	
	std::cout << std::endl << "Content of the array: ";
	for  (it = container.begin(); it != container.end(); it++ )
		std::cout << *it << " ";
	std::cout << std::endl;
}

template<typename T>
void	fillContainer( T& container )
{
	srand(time (NULL));
	for ( int i = 0; i < 20; i++ )
	 	container.insert( container.end(), (rand() % 50) );
}

template<typename T>
void	test( T& container, int toFind1, int toFind2, int toFind3 )
{
	fillContainer( container );
	displayContainer( container );

//<--- Try to find toFind1 --->
	try
	{
		typename T::const_iterator	it = easyfind( container, toFind1 );
		std::cout << std::endl << *it << " found in the container" << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl;
		std::cerr << e.what() << " catched. " << toFind1 << " not found." << std::endl;
	}

//<--- Try to find toFind2 --->	
	try
	{
		typename T::const_iterator	it = easyfind( container, toFind2 );
		std::cout << std::endl << *it << " found in the container" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl;
		std::cerr << e.what() << " catched. " << toFind2 << " not found." << std::endl;
	}

//<--- Try to find toFind2 --->
	try
	{
		typename T::const_iterator	it = easyfind( container, toFind3 );
		std::cout << std::endl << *it << " found in the container" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl;
		std::cerr << e.what() << " catched. " << toFind3 << " not found." << std::endl;
	}
	
}

#endif
