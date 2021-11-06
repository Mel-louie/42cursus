/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:44:38 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/06 14:14:39 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <iostream>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack<T>( void ) {}
	MutantStack<T>( const MutantStack& cpy ): std::stack<T>(cpy) {}

	virtual ~MutantStack<T>( void ) {}

	MutantStack<T>&	operator=( const MutantStack& src )
	{
		return (std::stack<T>::operator=( src ));
	}

	typedef typename std::deque<T>::iterator	iterator;
	iterator	begin()
	{
		return ( std::stack<T>::c.begin() );
	}

	iterator	end()
	{
		return ( std::stack<T>::c.end() );
	}
};

#endif
