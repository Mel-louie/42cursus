/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:27:10 by mdesfont          #+#    #+#             */
/*   Updated: 2021/12/15 11:19:56 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef vector_HPP
# define vector_HPP

# include <iostream>
# include "vector_iterator.hpp"

using namespace ft;

class iterator;

namespace	ft
{
	/*--------------------------------------------------------*/
	/*---------------------- FT::vector ----------------------*/
	/*
    *   @param T        Type of container's elements.
    *   @param Alloc    Object used to manage the vector' storage.
	*/

	template <typename T, class Alloc = std::allocator<T> >
	class vector
	{

	/*							Attributes					*/
	private:
		Alloc	_alloc;			// Copy of allocation type object
		size_t _size;
		size_t _capacity;
		T   *_vector;			// pointer to a dynamically allocated array

		template <typename U>
		void	swap(U &a, U &b)
		{
			U	tmp;

			tmp = a;
			a = b;
			b = tmp;
		}

    public:

	

	/*							Aliases						*/
	typedef	Alloc	allocator_type;
	typedef	T		value_type;
	typedef	size_t	size_type;

	typedef typename ft::iterator<int*>      iterator;
    typedef typename ft::iterator<const int*>       const_iterator;

	/*							Constructors				*/
	/*
	*   Default constructor
    *   Construct an empty container with 0 element		*
	*   @param alloc 		is use for the allocation
	*/
		explicit	vector(const allocator_type& alloc = allocator_type()):
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
		explicit vector (size_type n, const value_type& val = value_type(),
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
		vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type()):
			_alloc(alloc), _size(0)
		{
			InputIterator	tmp(first);
			while (tmp != last)
				_size++;
			_capacity = _size;

			_vector = _alloc.allocate(_capacity);

			for (int i = 0 ; i < last ; ++i, ++first)
				_alloc.construct(&_vector[i], &first);
			
		}

	/*
	*	Copy constructor
    *   @param x	object to be copied
	*/
		vector	(const vector &x): _alloc(x._alloc), _size(x._size),
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
		~vector()
		{
			for (iterator it = begin() ; it != end() ; ++it )
				_alloc.destroy(&(*it));
			_alloc.deallocate(_vector, _capacity);
		}

	/*
	*	Assignation operator
	*	@param x 	the iteration that will be assigned
	*/
		vector&	operator=(const vector &x)
		{
			vector	tmp(x);			//copy x
			
			swap(tmp);				//swap tmp with this
			return (*this);
		}

	/*							Iterators					*/
	/*	Return (const_)iterator to beginning						*/
		iterator	begin() { return (iterator(_vector)); }
		const_iterator	begin() const { return (const_iterator(_vector)); }

	/*	Return (const_)iterator to end						*/
		iterator end() { return (iterator(_vector + _size)); }
		const_iterator	end() const { return (const_iterator_type(_vector + _size)); }

	
		// rev_iterator_type	rbegin() { return (rev_iterator_type(_vector)); }
		// rev_iterator_type	rend() { return (rev_iterator_type(_vector)); }

	/*							Capacity					*/
	/*							Element access				*/
	/*							Modifiers					*/

		void	swap(vector &x)
		{
			swap(_alloc, x._alloc);
			swap(_capacity, x._capacity);
			swap(_size, x._size);
			swap(_vector, x._vector);
		}
	
	/*							Allocator					*/
	/*				Non-member function overloads			*/
	};
};

#endif
