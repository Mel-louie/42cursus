/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:23:52 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/05 15:44:15 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/span.hpp"


Span::Span( void )
{
	_size_max = 0;
	return ;
}

Span::Span( unsigned int N) : _size_max( N )
{
	return ;
}

Span::Span( const Span& cpy )
{
	*this = cpy;
	return ;
}

Span::~Span( void )
{
	return ;
}

Span &Span::operator=( const Span& src )
{
	_nbs = src._nbs;
	_size_max = src._size_max;
	return ( *this );
}

void Span::addNumber( int nb )
{
	if (this->_nbs.size() < _size_max)
		_nbs.push_back( nb );
	else
		throw ( Span::object_full() );
	return ;
}

unsigned int Span::shortestSpan( void )
{
	if ( _nbs.size() <= 1 )
		throw ( no_span() );
	std::sort( _nbs.begin(), _nbs.end() );
	std::vector<int>::iterator it = _nbs.begin();
	std::vector<int>::iterator it2 = _nbs.begin() + 1;
	int ret = *it2 - *it;
	for (; it < _nbs.end() - 1; it++, it2++)
	{
		ret = ( ret < *it2 - *it ) ? ret : *it2 - *it;
	}
	return ( ret );
}

unsigned int Span::longestSpan()
{
	if ( _nbs.size() <= 1 )
		throw ( no_span() );
	std::sort(_nbs.begin(), _nbs.end());

	return ( _nbs.back() - _nbs.front() );
}

const char *Span::object_full::what() const throw ()
{
	return ("Object is full");
}

const char *Span::no_span::what() const throw ()
{
	return ("No span to find");
}