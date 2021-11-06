/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:23:52 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/06 16:46:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/span.hpp"

Span::Span( void ): _sizeMax(0), _nbs() {}

Span::Span( unsigned int N ): _sizeMax(N), _nbs() {}

Span::Span( const Span& cpy ): _sizeMax(cpy._sizeMax), _nbs(cpy._nbs) {}

Span::~Span( void ) {}


Span&	Span::operator=( const Span& src )
{
	if ( this != &src )
	{
		this->_sizeMax = src.getSizeMax();
		this->_nbs.clear();
		this->_nbs.assign( src._nbs.begin(), src._nbs.end() );
	}
	return ( *this );
}

int	Span::getSizeMax( void ) const
{
	return ( this->_sizeMax );
}

int	Span::getSize( void ) const
{
	return ( this->_nbs.size() );
}

void	Span::setSizeMax( unsigned int sizeMax )
{
	this->_sizeMax = sizeMax;
}

void	Span::addNumber( int n )
{
	if ( this->getSize() == this->getSizeMax() )
		throw Span::SpanIsFull();
	
	this->_nbs.push_back( n );
}

void	Span::addNumbers( std::vector<int>::const_iterator start, std::vector<int>::const_iterator end)
{
	for ( std::vector<int>::const_iterator it = start; it != end; ++it )
	{
		if ( this->getSize() == this->getSizeMax() )
			throw Span::SpanIsFull();

		this->_nbs.push_back( *it );
	}
}

void	Span::addVector( const std::vector<int>& v )
{
	try
	{
		addNumbers( v.begin(), v.end() );
	}
	catch ( Span::SpanIsFull& e )
	{
		std::cout << "Can't add more numbers because " << e.what() << std::endl;
	}
}

void	Span::displayNumber( void )
{
	for ( std::vector<int>::iterator it = this->_nbs.begin(); it != this->_nbs.end(); it++ )
		std::cout << *it << " ";
	std::cout << std::endl;
}

unsigned int Span::shortestSpan() {

	if (_nbs.size() <= 1)
		throw (NoSpan());

	std::sort(_nbs.begin(), _nbs.end());
	std::vector<int>::iterator it = _nbs.begin();
	std::vector<int>::iterator it2 = _nbs.begin() + 1;
	
	int ret = *it2 - *it;
	for (; it < _nbs.end() - 1; it++, it2++)
	{
		ret = (ret < *it2 - *it) ? ret : *it2 - *it;
	}
	return (ret);
}

unsigned int Span::longestSpan() {

	if (_nbs.size() <= 1)
		throw (NoSpan());

	std::sort(_nbs.begin(), _nbs.end());
	return (_nbs.back() - _nbs.front());
}

const char *Span::SpanIsFull::what() const throw () {

	return ("Exception: can't add another number, the oject is full.");
}

const char *Span::NoSpan::what() const throw () {

	return ("exception, no span to find.");
}
