/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:27:10 by mdesfont          #+#    #+#             */
/*   Updated: 2021/12/13 18:08:10 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_CPP

# include <iostream>
# include "vector_iterator.hpp"

class iterator;

namespace	ft
{
	/*--------------------------------------------------------*/
	/*---------------------- FT::VECTOR ----------------------*/
	/*
    *   @param T        Type of container's elements.
    *   @param Alloc    Object used to manage the vector' storage.
	*/

	template <typename T, class Alloc = std::allocator<T> >
	class Vector
	{

	/*							Attributes					*/
	private:
		Alloc	_alloc;			// Copy of allocation type object
		size_t _size;
		size_t _capacity;
		T   *_vector;			// pointer to a dynamically allocated array

    public:

	/*							Aliases						*/
	typedef	Alloc	allocator_type;
	typedef	T		value_type;
	typedef	size_t	size_type;

	/*							Constructors				*/
	/*
	*   Default constructor
    *   Construct an empty container with 0 element		*
	*   @param alloc 		is use for the allocation
	*/
		explicit	Vector(const allocator_type& alloc = allocator_type()):
			_alloc(alloc), _size(0), _capacity(0)
		{
			_vector = _alloc.allocate(_capacity);
		}

	/*   
	*	Fill constructor
    *   @param n		the number of elements to create
	*   @param val 	the value used by default for init
	*   @param alloc 	the allocation
	*/
		explicit Vector (size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()):
			_alloc(alloc), _size(n), _capacity(n)
		{
			_vector = _alloc.allocate(_capacity);

			for (size_type i = 0 ; i < _size ; ++i)
				_alloc.construct(&_vector[i], val);
		}

	/*
	*	Range constructor
    *   @param first	begining of the range
	*   @param last 	end of the range
	*   @param alloc 	the allocation
	*/
		template <class InputIterator>
		Vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type()):
			_alloc(alloc), _size(0)
		{
			InputIterator	tmp(first);
			while (tmp != last)
				_size++;
			_capacity = _size;

			_vector = _alloc.allocate(_capacity);

			for (int i = 0 ; i < last ; ++i, ++first)
				_alloc.construct(&_vector[i], first);
			
		}

	/*
	*	Copy constructor
    *   @param x	object to be copied
	*/
		Vector	(const Vector &x): _alloc(x._alloc), _size(x._size),
			_capacity(x._capacity)
		{
			_vector = _alloc.allocate(_capacity);

			for (size_type i = 0 ; i < _size ; ++i)
				_alloc.construct(&_vector[i], &x._vector[i]);
		}

	/*
	*	Destuctor
	*	destroys all container elements, and deallocates
	*	all the storage capacity allocated by the vector
	*	using its allocator
	*/
		~Vector()
		{
			
		}
	};
};

#endif
