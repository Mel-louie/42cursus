/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:14:59 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/03 20:58:40 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
private:
	T*	_array;
	unsigned int	_arraySize;

public:
	Array( void );
	Array( unsigned int n );
	Array( const Array& cpy );
	~Array( void );

	Array&	operator=( const Array& src );

	T&	operator[]( unsigned int position ) const;

//getters
	unsigned int	size( void ) const;
	T*	getArray( void ) const;

	class OfLimitsException: public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	
};

// <------------ IMPLEMENTATION ------------>

template<typename T>
Array<T>::Array( void ): _array( new T[0] ), _arraySize( 0 )
{
	for (unsigned int i = 0; i < _arraySize; i++)
	{
		this->_array[i] = T();
	}
	
}

template<typename T>
Array<T>::Array( unsigned int n ): _array( new T[n] ), _arraySize( n ) {
	for (unsigned int i = 0; i < _arraySize; i++)
	{
		this->_array[i] = T();
	}
	
}

template<typename T>
Array<T>::Array( const Array& cpy ): _arraySize( cpy._arraySize)
{
	this->_array = new T[cpy._arraySize];

	for ( unsigned int i = 0; i < cpy._arraySize; i++ )
		this->_array[i] = cpy._array[i];
}

template<typename T>
Array<T>::~Array( void )
{
	delete [] this->_array;
}

template<typename T>
Array<T>&	Array<T>::operator=( const Array& src )
{
	if ( this != &src )
	{
		delete [] this->_array;

		this->_array = new T[src._arraySize];

		for ( unsigned int i = 0; i < src._arraySize; i++ )
			this->_array[i] = src._array[i];

		this->_arraySize = src._arraySize;
	}
	return ( *this );
}

template<typename T>
T&	Array<T>::operator[]( unsigned int position ) const
{
	if ( position >= this->_arraySize )
		//throw ( std::exception() );
		throw Array<T>::OfLimitsException();
	return ( this->_array[position]);
}

template<typename T>
unsigned int	Array<T>::size( void ) const
{
	return ( this->_arraySize );
}

template<typename T>
T*	Array<T>::getArray( void ) const
{
	return ( this->_array);
}

template<typename T>
const char*	Array<T>::OfLimitsException::what() const throw()
{
	return ( "Exception: position of the limits of the array" );
}

template<typename T>
void	displayElement( Array<T> &array, int i ) {
	try 
	{
		std::cout << array[i];
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

#endif
