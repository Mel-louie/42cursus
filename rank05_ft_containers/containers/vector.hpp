/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:27:10 by mdesfont          #+#    #+#             */
/*   Updated: 2021/12/21 17:19:48 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef vector_HPP
# define vector_HPP

# include <iostream>
# include <cmath>
# include <type_traits>
# include "../iterators/random_access_iterator.hpp"
# include "../iterators/reverse_iterators.hpp"
# include "../templates/type_traits.hpp"

namespace	ft
{
	/*--------------------------------------------------------*/
	/*---------------------- FT::VECTOR ----------------------*/
	/*
    *   @param T        Type of container's elements.
    *   @param Alloc    Object used to manage the vector' storage.
	*/

	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
    public:
	/*							Aliases						*/
	typedef	Alloc				allocator_type;
	typedef	T					value_type;
	typedef value_type*			pointer;
	typedef const value_type*	const_pointer;
	typedef value_type&			reference;
	typedef const value_type&	const_reference;
	typedef	size_t				size_type;
	typedef	std::ptrdiff_t		difference_type;	// ptrdiff_t: Result of pointer subtraction

	typedef randomAccess<T>			iterator;
	typedef randomAccess<const T>	const_iterator;

	typedef	reverseIterator<T>			rev_interator;
	typedef	reverseIterator<const T>	const_rev_interator;


/*--------------------------------------------------------*/
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
//https://stackoverflow.com/questions/56061096/whats-is-type-in-the-expression-stdenable-if
//https://stackoverflow.com/questions/51785354/how-does-stdenabled-if-work-when-enabling-via-a-parameter
//https://stackoverflow.com/questions/21042872/how-to-implement-fill-constructor-and-range-constructor-for-sequence-containers
//https://riptutorial.com/cplusplus/example/3777/enable-if
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0):
			_alloc(alloc), _size(0)
		{
			InputIterator	tmp(first);
			while (tmp != last)
				_size++;
			_capacity = _size;

			_vector = _alloc.allocate(_capacity);

			for (int i = 0 ; i < last ; ++i, ++first)
				_alloc.construct(&_vector[i], *first);
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

/*--------------------------------------------------------*/
/*							Iterators					*/
	/*	Return (const_)iterator to beginning				*/
		iterator		begin() { return (iterator(_vector)); }
		const_iterator	begin() const { return (const_iterator(_vector)); }

	/*	Return (const_)iterator to end						*/
		iterator 		end() { return (iterator(_vector + _size)); }
		const_iterator	end() const { return (const_iterator(_vector + _size)); }

	/*	Return (const_)iterator to reverse beginning		*/
		rev_interator	rbegin() { return (rev_interator(_vector + _size - 1)); }
		const_rev_interator	rbegin() const { return (const_rev_interator(_vector + _size - 1)); }
	
	/*	Return (const_)iterator to reverse end				*/
		rev_interator	rend() { return (rev_interator(_vector - 1)); }
		const_rev_interator	rend() const { return (const_rev_interator(_vector - 1)); }

/*--------------------------------------------------------*/
/*							Capacity					*/
	/*
	*	Returns the number of elements in the vector
	*/
		size_type size() const { return (_size); }
	/*
	*	Returns the maximum number of elements that the vector can hold
	*	This is the maximum potential size the container can reach due
	*	to known system or library implementation limitations
	*/
		size_type max_size() const
		{
			return (_alloc.max_size()) ;
		}

	/*
	*	Resizes the container so that it contains n elements
	*   @param n	new container size, n = number of elements
	*   @param val 	Object whose content is copied to the added
	*		elements in case that n is greater than the current
	*		container size. If not specified, the default
	*		constructor is used instead.
	*/
		void resize (size_type n, value_type val = value_type())
		{
			if (n > _capacity)
				reallocate(n);
			while (n > _size)
				push_back(val);
			while (n < _size)
				pop_back();
		}
	/*
	*	Return size of allocated storage capacity
	*/
		size_type capacity() const { return (_capacity); }
	
	/*
	*	 Returns whether the vector is empty (i.e. whether its size is 0)
	*/
		bool empty() const	{ return (_size == 0); };
	/*
	*	Request a change in capacity
	*/
		void reserve (size_type n)
		{
			if (n > max_size())
				std::length_error("not enough space");
			if (n > _capacity)
				reallocate(n);
		}

/*--------------------------------------------------------*/
/*							Element access				*/

		T&			operator[](size_type n)	{ return (_vector[n]); }
		const T&	operator[](size_type n)	const { return (_vector[n]); }
	/*
	*	Access an element at n index
	*	If n is outside vector's range, throw an out_of_range exception
	*/
		T& at (size_type n)
		{
			if (!(n < _size))
				std::out_of_range("out of range");
			return (_vector[n]);
		}
		const T& at (size_type n) const
		{
			if (!(n < _size))
				std::out_of_range("out of range");
			return (_vector[n]);
		}
	/*
	*	 Returns a reference to the first element in the vector
	*/
		T& 			front() { return (_vector[0]); }
		const T&	front() const { return (_vector[0]); }
	/*
	*	 Returns a reference to the last element in the vector
	*/
		T& 			back() { return (_vector[_size - 1]); }
		const T&	back() const { return (_vector[_size - 1]); }

/*------------------------------------------------------*/
/*							Modifiers		   			*/

	/*
	*	The new contents are elements constructed from each of the elements in the
	*	range between first and last, in the same order
	*	if a reallocation happens,the storage needed is allocated using the internal allocator.
	*	@param first    an iterator pointing at the beginning of the range (will be included).
    *   @param last     an iterator pointing at the end of the range (will not be included)
	*/
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last)
		{
			clear();

			size_type n = static_cast<size_type>(last - first);
			if (n > _capacity)
			{
				_alloc.deallocate(_vector, _capacity);
				_vector = _alloc.allocate(n);
			}
						
			size_type i = 0;
			for (; first != last; ++i, ++first)
				_alloc.construct(&_vector[i], *first);
			_size = i;
		}
	/*
	*	the new contents are n elements, each initialized to a copy of val
	*	if a reallocation happens,the storage needed is allocated using the internal allocator.
	*/
		void assign (size_type n, const value_type& val)
		{
			clear();

			if (n > _capacity)
			{
				_alloc.deallocate(_vector, _capacity);
				_vector = _alloc.allocate(n);
			}
						
			for (size_type i = 0 ; i < n ; ++i)
				_alloc.construct(&_vector[i], val);
			_size = n;
		}

	/*
	*	Add  new element at the end of the vector
	*	When the capacity is exhausted and more is needed,
	*	it is automatically expanded by the container
	*	(reallocating it storage space). The theoretical
	*	limit on the size of a vector is given by member max_size.
	*/
		void push_back (const value_type& val)
		{
			if (_size + 1 > _capacity)
			{
				if (!_capacity)
					reallocate(1);
				else
					reallocate(_capacity * 2);
			}
			_alloc.construct(&_vector[_size++], val);
		}
	/*
	*	Delete last element
	*	Removes the last element in the vector, effectively
	*	reducing the container size by one.
	*	This destroys the removed element.
	*/
		void pop_back()
		{
			if (_size)
				_alloc.destroy(&_vector[_size--] - 1);				
		}

		/*
		*	Removes from the vector a single element (position)
		*	@param position	iterator pointing to a single element to be removed from the vector
		*/
		iterator erase (iterator position) { return (erase(position, position + 1)); }
		/*
		*	Removes from the vector a range of elements ([first,last))
		*	@param first	iterator first of the range to erase, that will be include
		*	@param last		iterator last of the range to erase, that will not be include
		*/
		iterator erase (iterator first, iterator last)
		{
			(void) first, last;
		}
		/*
		*	 Exchanges the content of the container by the content of x, which is another vector
		*	object of the same type. Sizes may differ
		*/
		void	swap(vector &x)
		{
			swap(_alloc, x._alloc);
			swap(_capacity, x._capacity);
			swap(_size, x._size);
			swap(_vector, x._vector);
		}
		/*
		*	Removes all elements from the vector (which are destroyed),
		*	leaving the container with a size of 0
		*/
		void clear()
		{
			while (_size)
				pop_back();
		}
		
/*------------------------------------------------------*/
/*							Allocator					*/
	/*
	*	 Returns a copy of the allocator object associated with the vector
	*/
		allocator_type get_allocator() const { return (_alloc); }



/*------------------------------------------------------*/
/*							Attributes					*/
	protected:
		allocator_type	_alloc;			// Copy of allocation type object
		size_type		_size;
		size_type		_capacity;
		pointer			_vector;			// pointer to a dynamically allocated array

		template <typename U>
		void	swap(U &a, U &b)
		{
			U	tmp;

			tmp = a;
			a = b;
			b = tmp;
		}
		
		void	reallocate(size_type n)
		{
			T*	tmp = _alloc.allocate(n);

			for (size_type i = 0 ; i < _size ; ++i )
				_alloc.construct(&tmp[i], _vector[i]);
			this->~vector();
			_capacity = n;
			_vector = tmp;
		}
	};
/*------------------------------------------------------*/
/*				Non-member function overloads			*/
	/*
	*	Relational operators for vector
	*	Performs the appropriate comparison operation between the vector
	*	containers lhs and rhs.
	*/
		
	/*
	*	exchange contents of vectors
	*/
	template <class T, class Alloc>
	void swap(ft::vector<T, Alloc>& x, ft::vector<T, Alloc>& y) { x.swap(y); }
};

#endif //namespace fr --- VECTOR_HPP