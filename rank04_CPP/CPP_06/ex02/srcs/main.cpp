/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:45:14 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/02 22:51:50 by louielouie       ###   ########.fr       */
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

	std::cout << "<--- Identify the class generate --->" << std::endl;
	std::cout << " NB: the 2 outputs should be the same." << std::endl;
	std::cout << std:: endl;

	std::cout << "Identify the class by casting pointer:\t\t";
	identify( i );	
	std::cout << "Identify the class by casting reference:\t";
	identify( *i );	

	//leaks macos
	// system( "leaks base" );

	return (0);
}
