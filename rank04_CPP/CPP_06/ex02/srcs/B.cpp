/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:52:08 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/02 21:56:45 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/B.hpp"

B::B( void )
{
	return ;
}

B::B( B const& cpy )
{
	*this = cpy;
	return ;
}

B::~B( void )
{
	return ;
}

B&	B::operator=( B const& src )
{
	( void )src;
	return ( *this );
}
