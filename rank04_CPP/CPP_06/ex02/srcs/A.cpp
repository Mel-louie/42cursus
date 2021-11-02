/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:52:08 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/02 21:54:47 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A.hpp"

A::A( void )
{
	return ;
}

A::A( A const& cpy )
{
	*this = cpy;
	return ;
}

A::~A( void )
{
	return ;
}

A&	A::operator=( A const& src )
{
	( void )src;
	return ( *this );
}
