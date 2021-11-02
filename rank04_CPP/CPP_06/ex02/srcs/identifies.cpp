/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifies.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:46:25 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/02 22:48:59 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include "../includes/identifies.hpp"
#include <ctime>
#include <cstdlib>

Base*	generate( void )
{
	int	random;

//generate randomly a number between 0, 1 and 2
	srand( time (NULL) );
	random = ( rand() % 3 );

	if ( random == 0 )
		return ( new A() );
	else if ( random == 1 )
		return ( new B() );
	else if ( random == 2 )
		return ( new C() );
	
	return ( NULL );
}

//failed dynamic casts are indicated by a null pointer when casting pointers
void	identify( Base* p )
{
	if ( dynamic_cast<A *>( p ) != NULL )
		std::cout << "A" << std::endl;
	else if ( dynamic_cast<B *>( p ) != NULL )
		std::cout << "B" << std::endl;
	else if ( dynamic_cast<C *>( p ) != NULL )
		std::cout << "C" << std::endl;
}

//failed dynamic casts are indicated by an exception when casting references
void	identify( Base& p)
{
	try
	{
		( void )dynamic_cast<A &>( p );
		std::cout << "A" << std::endl;
	}
	catch( const std::exception& badCast )
	{
		try
		{
			( void )dynamic_cast<B &>( p );
			std::cout << "B" << std::endl;
		}
		catch( const std::exception& badCast )
		{
			try
			{	
				( void )dynamic_cast<C &>( p );
				std::cout << "C" << std::endl;
			}
			catch( const std::exception& badCast )
			{
				std::cerr << "Bad cast, something went wrong. Unknow type." << std::endl;
			}
			
		}
	}
	
}
