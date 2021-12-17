/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:27:10 by mdesfont          #+#    #+#             */
/*   Updated: 2021/12/17 18:12:13 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef vector_HPP
# define vector_HPP

# include <iostream>
# include <cmath>
# include "../iterators/random_access_iterator.hpp"

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
	typedef const value_type*			const_pointer;
	typedef value_type&			reference;
	typedef const value_type&	const_reference;
	typedef	size_t	size_type;

	typedef randomAcess<T>			iterator;
	typedef randomAcess<const T>	const_iterator;


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

/*							Iterators					*/
	/*	Return (const_)iterator to beginning				*/
		iterator		begin() { return (iterator(_vector)); }
		const_iterator	begin() const { return (const_iterator(_vector)); }

	/*	Return (const_)iterator to end						*/
		iterator 		end() { return (iterator(_vector + _size)); }
		const_iterator	end() const { return (const_iterator(_vector + _size)); }

	// /*	Return (const_)iterator to reverse beginning		*/
	// 	reverse_iterator	rbegin() { return (reverse_iterator(_vector + _size - 1)); }
	// 	const_reverse_iterator	rbegin() const { return (const_reverse_iterator(_vector + _size - 1)); }
	
	// /*	Return (const_)iterator to reverse end				*/
	// 	reverse_iterator	rend() { return (reverse_iterator(_vector - 1)); }
	// 	const_reverse_iterator	rend() const { return (const_reverse_iterator(_vector - 1)); }

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
			if (n > max_size)
				std::length_error("not enough space");
			if (n > _capacity)
				reallocate(n);
		}


/*							Element access				*/

		T&	operator[](size_type n)	{ return (_vector[n]); }

/*							Modifiers					*/

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

		void	swap(vector &x)
		{
			swap(_alloc, x._alloc);
			swap(_capacity, x._capacity);
			swap(_size, x._size);
			swap(_vector, x._vector);
		}
	
/*							Allocator					*/
/*				Non-member function overloads			*/

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
		

	/*----------------- REVERSE_ITERATORS -----------------*/
	/*			+---+---+---+---+---+---+---+
				|   | 1 | 2 | 3 | 4 | 5 |   |
				+---+---+---+---+---+---+---+
				  ↑   ↑               ↑   ↑
				  |   |               |   |
			   rend() |         rbegin()  end()
					  |                   rbegin().base()
				   begin()
				   rend().base()							*/
	// 	class reverse_iterator
	// 	{
	// 	private:
	// 		T*	_ptr;
	// 	public:
	// 		reverse_iterator(T* x ): _ptr(x) {}
	// 		reverse_iterator	(const reverse_iterator &cpy) { _ptr = cpy.getPtr(); }
	// 		~reverse_iterator() {}
	// 		reverse_iterator&	operator=(const reverse_iterator &x)
	// 		{
	// 			if (this != x._ptr)
	// 				this = x._ptr;
	// 			return (*this);
	// 		}
	// 		T*	getPtr() const { return (_ptr); }
	// 		T&	operator*() const { return (*_ptr); }
	// 		T*	operator->() const { return (_ptr); }

	// 		bool operator==(const reverse_iterator &it) { return (it._ptr == this->_ptr); }
	// 		bool operator!=(const reverse_iterator &it) { return (it._ptr == this->_ptr); }
	// 		bool operator<=(const reverse_iterator &it) { return (it._ptr >= this->_ptr); }
	// 		bool operator>=(const reverse_iterator &it) { return (it._ptr <= this->_ptr); }
	// 		bool operator<(const reverse_iterator &it) { return (it._ptr > this->_ptr); }
	// 		bool operator>(const reverse_iterator &it) { return (it._ptr < this->_ptr); }
			
	// 		reverse_iterator&	operator++() { _ptr--; return (*this); }
	// 		reverse_iterator	operator++(int) { reverse_iterator tmp(this->_ptr); this->_ptr--; return (tmp); }
	// 		reverse_iterator&	operator--() { _ptr++; return (*this); }
	// 		reverse_iterator	operator--(int) { reverse_iterator tmp(this->_ptr); this->_ptr++; return (tmp); }
			
	// 		reverse_iterator&	operator+=(const reverse_iterator &y)
	// 		{
	// 			this->_ptr = this->_ptr + y._ptr;
	// 			return (*this);
	// 		}
			
	// 		reverse_iterator&	operator-=(const reverse_iterator &y)
	// 		{
	// 			this->_ptr = this->_ptr + y._ptr;
	// 			return (*this); 
	// 		}

	// 		/*			Non-members operators overloads			*/
	// 		friend reverse_iterator	operator+(int nb, const reverse_iterator &x)
	// 		{
	// 			reverse_iterator newIt(x);
	// 			return (newIt += nb);
	// 		}
			
	// 		friend reverse_iterator	operator-(int nb, const reverse_iterator &x)
	// 		{
	// 			reverse_iterator newIt(x);
	// 			return (newIt -= nb);
	// 		}
	// 	};
		
	// 	class const_reverse_iterator
	// 	{
	// 	private:
	// 		T*	_ptr;
	// 	public:
	// 		const_reverse_iterator(T* x ): _ptr(x) {}
	// 		const_reverse_iterator	(const const_reverse_iterator &cpy) { _ptr = cpy.getPtr(); }
	// 		~const_reverse_iterator() {}
	// 		const_reverse_iterator&	operator=(const const_reverse_iterator &x)
	// 		{
	// 			if (this != x._ptr)
	// 				this = x._ptr;
	// 			return (*this);
	// 		}
	// 		T*	getPtr() const { return (_ptr); }
	// 		T&	operator*() const { return (*_ptr); }
	// 		T*	operator->() const { return (_ptr); }

	// 		bool operator==(const const_reverse_iterator &it) { return (it._ptr == this->_ptr); }
	// 		bool operator!=(const const_reverse_iterator &it) { return (it._ptr == this->_ptr); }
	// 		bool operator<=(const const_reverse_iterator &it) { return (it._ptr >= this->_ptr); }
	// 		bool operator>=(const const_reverse_iterator &it) { return (it._ptr <= this->_ptr); }
	// 		bool operator<(const const_reverse_iterator &it) { return (it._ptr > this->_ptr); }
	// 		bool operator>(const const_reverse_iterator &it) { return (it._ptr < this->_ptr); }
			
	// 		const_reverse_iterator&	operator++() { _ptr--; return (*this); }
	// 		const_reverse_iterator	operator++(int) { const_reverse_iterator tmp(this->_ptr); this->_ptr--; return (tmp); }
	// 		const_reverse_iterator&	operator--() { _ptr++; return (*this); }
	// 		const_reverse_iterator	operator--(int) { const_reverse_iterator tmp(this->_ptr); this->_ptr++; return (tmp); }
			
	// 		const_reverse_iterator&	operator+=(const const_reverse_iterator &y)
	// 		{
	// 			this->_ptr = this->_ptr + y._ptr;
	// 			return (*this);
	// 		}
			
	// 		const_reverse_iterator&	operator-=(const const_reverse_iterator &y)
	// 		{
	// 			this->_ptr = this->_ptr + y._ptr;
	// 			return (*this); 
	// 		}

	// 		/*			Non-members operators overloads			*/
	// 		friend const_reverse_iterator	operator+(int nb, const const_reverse_iterator &x)
	// 		{
	// 			const_reverse_iterator newIt(x);
	// 			return (newIt += nb);
	// 		}
			
	// 		friend const_reverse_iterator	operator-(int nb, const const_reverse_iterator &x)
	// 		{
	// 			const_reverse_iterator newIt(x);
	// 			return (newIt -= nb);
	// 		}
	// 	};		
	};
};


// Print the inside of a vector
template<typename T>
std::ostream& operator<< (std::ostream& out,  ft::vector<T>& v)
{
    out << "{";
    size_t last = v.size() - 1;
    for(size_t i = 0; i < v.size(); ++i)
	{
        out << v[i];
        if (i != last) 
            out << ", ";
    }
    out << "}";
    return out;
}

#endif