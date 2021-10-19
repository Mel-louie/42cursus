/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:32:02 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/19 15:34:57 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen() {}

Karen::~Karen() {}

void	Karen::complain( std::string level )
{
	std::string	levels_arr[4] = {"debug", "info", "warning", "error"};
	void	(Karen::*ptr_functions[4])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	int	i = -1;

	while (++i < 4)
	{
		if ( level.compare(levels_arr[i]) == 0)
			(this->*ptr_functions[i])();
	}
}

void	Karen::debug( void )
{
	std::cout << "I love to get extra bacon "
	<< "for my 7XL-double-cheese-triple-pickle-special-ketchup burger. "
	<< "I just love it!" << std::endl;
}

void	Karen::info( void )
{
	std::cout << "I cannot believe adding extra "
	<< "bacon cost more money. You don’t put enough! "
	<< "If you did I would not have to ask for it!" << std::endl ;
}

void	Karen::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. "
	<< "I’ve been coming here for years "
	<< "and you just started working here last month." << std::endl;
}

void	Karen::error( void )
{
	std::cout << "This is unacceptable, "
	<< "I want to speak to the manager. NOW." << std::endl;
}
