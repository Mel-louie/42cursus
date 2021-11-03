/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:48:29 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/03 11:08:37 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap( T& a, T& b )
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
const T&	min( const T& a, const T& b )
{
	if ( a < b )
		return ( a );
	else if ( b < a )
		return ( b );
	else
		return ( b );
}

template<typename T>
const T&	max( const T& a, const T& b )
{
	if ( a > b )
		return ( a );
	else if ( b > a )
		return ( b );
	else
		return ( b );
}

#endif
