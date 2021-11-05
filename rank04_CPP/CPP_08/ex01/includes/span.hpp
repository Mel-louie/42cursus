/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:30:36 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/05 18:13:05 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <iostream>
#include <exception>

class Span
{
private:
	int	_sizeMax;
	std::vector<int>	_nbs;

public:
	Span( void );
	Span( unsigned int sizeMax );
	Span( const Span& cpy );
	~Span( void );

	Span&	operator=( const Span& src );

	//getters
	int	getSizeMax( void ) const;
	int	getSize( void ) const;
	//setter
	void	setSizeMax( unsigned int sizeMax);

	//member functions
	void	addNumber( int N );
	void	addNumbers( std::vector<int>::const_iterator start, std::vector<int>::const_iterator end);
	void	addVector( const std::vector<int>& v );

	void	displayNumber( void );

	unsigned int	shortestSpan( void );
	unsigned int	longestSpan( void );

	//exceptions
	class SpanIsFull: public std::exception
	{
	public:
		const char*	what() const throw();
	};
	
	class NoSpan: public std::exception
	{
	public:
		const char*	what() const throw();
	};
};


#endif
