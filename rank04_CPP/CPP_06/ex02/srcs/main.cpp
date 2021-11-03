/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:45:14 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/04 00:25:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include "../includes/identifies.hpp"

int	main( void )
{
	Base*	i = generate();

	if ( i != NULL )
	{
		std::cout << "<--- Identify the class generate --->" << std::endl;
		std::cout << " NB: the 2 outputs should be the same." << std::endl;
		std::cout << std:: endl;

		std::cout << "Identify the class by casting pointer:\t\t";
		identify( i );	
		std::cout << "Identify the class by casting reference:\t";
		identify( *i );	
	}
	else 
		std::cerr << "An error occures when instance allocation" << std::endl;

	delete i;

	//leaks macos
	// system( "leaks base" );

	return (0);
}
