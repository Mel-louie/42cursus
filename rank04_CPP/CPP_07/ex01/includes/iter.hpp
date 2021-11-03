/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:52:31 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/03 14:02:00 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	plusTen( T& t)
{
	std::cout << t + 10 << " ";
}

template<typename T>
void	iter( T* arrAdr, int len, void (*func)(T&) )
{
	for ( int i = 0; i < len; i++ )
		func( arrAdr[i] );
}

#endif
