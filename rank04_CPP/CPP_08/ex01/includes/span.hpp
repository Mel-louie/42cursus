/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:30:36 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/05 15:43:32 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>

class Span
{
private:
	std::vector<int> _nbs;
	size_t _size_max;

	class object_full: public std::exception {

	public:
	
		const char *what() const throw();
	
	};
	class no_span: public std::exception {

	public:
	
		const char *what() const throw();
	
	};

	Span();

public:
	Span( unsigned int N );
	Span( const Span& cpy );
	~Span( void );

	Span&	operator=( const Span& src );

	void	addNumber( int nb );
	template<typename T>
	void addNumber( T start, T end ) {		

		for ( T it = start; it < end; it++ ) {
			if ( this->_nbs.size() < _size_max )
				_nbs.push_back( *it );
			else
				throw (Span::object_full());
		}
		return ;
	}
	unsigned int shortestSpan( void );
	unsigned int longestSpan( void );
};

#endif
