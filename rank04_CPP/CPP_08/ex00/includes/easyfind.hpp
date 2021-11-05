/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:30:36 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/05 13:18:12 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template<typename T>
typename T::const_iterator	easyfind( const T& container, int toFind )
{
	typename T::const_iterator	it;

	it = std::find( container.begin(), container.end(), toFind);

	if ( it == container.end() )
			throw std::exception();
	
	return ( it );
}

#endif
