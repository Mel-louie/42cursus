/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:52:08 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/02 21:58:52 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/C.hpp"

C::C( void )
{
	return ;
}

C::C( C const& cpy )
{
	*this = cpy;
	return ;
}

C::~C( void )
{
	return ;
}

C&	C::operator=( C const& src )
{
	( void )src;
	return ( *this );
}
