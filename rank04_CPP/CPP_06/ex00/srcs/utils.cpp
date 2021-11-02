/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:56:35 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/02 16:09:06 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/converter.hpp"

void	displayUsage( void )
{
	std::cout << "This programm needs one argument. A char, an int, a float or a double"
	<< std::endl;
	return ;
}

int	checkLitteraleValue( char* end )
{
	if ( !end || !( *end ) )
		return (0);

	int i = 0;

	if ( end[i] != 'f' && !isspace(end[i]) )
		return (1);
	else
	{
		while ( end[++i] )
			if ( !isspace(end[i]) )
				return (1);
	}
	return (0);
}
