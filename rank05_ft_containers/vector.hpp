/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:27:10 by mdesfont          #+#    #+#             */
/*   Updated: 2021/12/15 13:32:56 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef vector_HPP
# define vector_HPP

# include <iostream>
// # include "vector_iterator.hpp"


namespace	ft
{
	/*--------------------------------------------------------*/
	/*---------------------- FT::VECTOR ----------------------*/
	/*
    *   @param T        Type of container's elements.
    *   @param Alloc    Object used to manage the vector' storage.
	*/

	template <typename T, class Alloc = std::allocator<T> >
	class vector
	{
    public:

	class iterator;
	class const_iterator;
	class reverse_iterator;
	class const_reverse_iterator;

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
			std::cout << "detruit :)" << std::endl;
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
		iterator	begin() { return (iterator(_vector)); }
		const_iterator	begin() const { return (const_iterator(_vector)); }

	/*	Return (const_)iterator to end						*/
		iterator end() { return (iterator(_vector + _size)); }
		const_iterator	end() const { return (const_iterator_type(_vector + _size)); }

	/*	Return (const_)iterator to reverse beginning		*/
		reverse_iterator	rbegin() { return (reverse_iterator(_vector + _size - 1)); }
		const_reverse_iterator	rbegin() const { return (const_reverse_iterator(_vector + _size - 1)); }
	
	/*	Return (const_)iterator to reverse end				*/
		reverse_iterator	rend() { return (reverse_iterator(_vector - 1)); }
		const_reverse_iterator	rend() const { return (const_reverse_iterator(_vector - 1)); }
	
	

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
		
	/*--------------------------------------------------------*/
	/*----------------- FT::VECTOR_ITERATORS -----------------*/
	public:
	class iterator
	{
		private:
			T*	_ptr;
		public:
			iterator(T* x ): _ptr(x) {}
			iterator	(const iterator &cpy) { _ptr = cpy.getPtr(); }
			~iterator() {}
			iterator&	operator=(const iterator &x)
			{
				if (this != x._ptr)
					this = x._ptr;
				return (*this);
			}
			T*	getPtr() const { return (_ptr); }
			T&	operator*() const { return (*_ptr); }
			T*	operator->() const { return (_ptr); }

			bool operator==(const iterator &it) { return (it._ptr == this->_ptr); }
			bool operator!=(const iterator &it) { return (it._ptr == this->_ptr); }
			bool operator<=(const iterator &it) { return (it._ptr >= this->_ptr); }
			bool operator>=(const iterator &it) { return (it._ptr <= this->_ptr); }
			bool operator<(const iterator &it) { return (it._ptr > this->_ptr); }
			bool operator>(const iterator &it) { return (it._ptr < this->_ptr); }
			
			iterator&	operator++() { _ptr++; return (*this); }									// prefix increment operator: --it
			iterator	operator++(int) { iterator tmp(this->_ptr); this->_ptr++; return (tmp); }	// postfix increment operator: it--
			iterator&	operator--() { _ptr--; return (*this); }									// prefix decrement operator: --it
			iterator	operator--(int) { iterator tmp(this->_ptr); this->_ptr--; return (tmp); }	// postfix decrement operator: it--
			
			iterator&	operator+=(const iterator &y)
			{
				this->_ptr = this->_ptr + y._ptr;
				return (*this);
			}
			
			iterator&	operator-=(const iterator &y)
			{
				this->_ptr = this->_ptr + y._ptr;
				return (*this); 
			}

			/*			Non-members operators overloads			*/
			friend iterator	operator+(int nb, const iterator &x)
			{
				iterator newIt(x);
				return (newIt += nb);
			}
			
			friend iterator	operator-(int nb, const iterator &x)
			{
				iterator newIt(x);
				return (newIt -= nb);
			}
		};
	
	class const_iterator
	{
		private:
			T*	_ptr;
		public:
			const_iterator(T* x ): _ptr(x) {}
			const_iterator	(const iterator &cpy) { _ptr = cpy.getPtr(); }
			~const_iterator() {}
			const_iterator&	operator=(const const_iterator &x)
			{
				if (this != x._ptr)
					this = x._ptr;
				return (*this);
			}
			T*	getPtr() const { return (_ptr); }
			T&	operator*() const { return (*_ptr); }
			T*	operator->() const { return (_ptr); }

			bool operator==(const const_iterator &it) { return (it._ptr == this->_ptr); }
			bool operator!=(const const_iterator &it) { return (it._ptr == this->_ptr); }
			bool operator<=(const const_iterator &it) { return (it._ptr >= this->_ptr); }
			bool operator>=(const const_iterator &it) { return (it._ptr <= this->_ptr); }
			bool operator<(const const_iterator &it) { return (it._ptr > this->_ptr); }
			bool operator>(const const_iterator &it) { return (it._ptr < this->_ptr); }
			
			const_iterator&	operator++() { _ptr++; return (*this); }									// prefix increment operator: --it
			const_iterator	operator++(int) { iterator tmp(this->_ptr); this->_ptr++; return (tmp); }	// postfix increment operator: it--
			const_iterator&	operator--() { _ptr--; return (*this); }									// prefix decrement operator: --it
			const_iterator	operator--(int) { iterator tmp(this->_ptr); this->_ptr--; return (tmp); }	// postfix decrement operator: it--
			
			const_iterator&	operator+=(const const_iterator &y)
			{
				this->_ptr = this->_ptr + y._ptr;
				return (*this);
			}
			
			const_iterator&	operator-=(const const_iterator &y)
			{
				this->_ptr = this->_ptr + y._ptr;
				return (*this); 
			}

			/*			Non-members operators overloads			*/
			friend const_iterator	operator+(int nb, const const_iterator &x)
			{
				const_iterator newIt(x);
				return (newIt += nb);
			}
			
			friend const_iterator	operator-(int nb, const const_iterator &x)
			{
				const_iterator newIt(x);
				return (newIt -= nb);
			}
		};
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
		class reverse_iterator
		{
		private:
			T*	_ptr;
		public:
			reverse_iterator(T* x ): _ptr(x) {}
			reverse_iterator	(const reverse_iterator &cpy) { _ptr = cpy.getPtr(); }
			~reverse_iterator() {}
			reverse_iterator&	operator=(const reverse_iterator &x)
			{
				if (this != x._ptr)
					this = x._ptr;
				return (*this);
			}
			T*	getPtr() const { return (_ptr); }
			T&	operator*() const { return (*_ptr); }
			T*	operator->() const { return (_ptr); }

			bool operator==(const reverse_iterator &it) { return (it._ptr == this->_ptr); }
			bool operator!=(const reverse_iterator &it) { return (it._ptr == this->_ptr); }
			bool operator<=(const reverse_iterator &it) { return (it._ptr >= this->_ptr); }
			bool operator>=(const reverse_iterator &it) { return (it._ptr <= this->_ptr); }
			bool operator<(const reverse_iterator &it) { return (it._ptr > this->_ptr); }
			bool operator>(const reverse_iterator &it) { return (it._ptr < this->_ptr); }
			
			reverse_iterator&	operator++() { _ptr--; return (*this); }
			reverse_iterator	operator++(int) { reverse_iterator tmp(this->_ptr); this->_ptr--; return (tmp); }
			reverse_iterator&	operator--() { _ptr++; return (*this); }
			reverse_iterator	operator--(int) { reverse_iterator tmp(this->_ptr); this->_ptr++; return (tmp); }
			
			reverse_iterator&	operator+=(const reverse_iterator &y)
			{
				this->_ptr = this->_ptr + y._ptr;
				return (*this);
			}
			
			reverse_iterator&	operator-=(const reverse_iterator &y)
			{
				this->_ptr = this->_ptr + y._ptr;
				return (*this); 
			}

			/*			Non-members operators overloads			*/
			friend reverse_iterator	operator+(int nb, const reverse_iterator &x)
			{
				reverse_iterator newIt(x);
				return (newIt += nb);
			}
			
			friend reverse_iterator	operator-(int nb, const reverse_iterator &x)
			{
				reverse_iterator newIt(x);
				return (newIt -= nb);
			}
		};
		
		class const_reverse_iterator
		{
		private:
			T*	_ptr;
		public:
			const_reverse_iterator(T* x ): _ptr(x) {}
			const_reverse_iterator	(const const_reverse_iterator &cpy) { _ptr = cpy.getPtr(); }
			~const_reverse_iterator() {}
			const_reverse_iterator&	operator=(const const_reverse_iterator &x)
			{
				if (this != x._ptr)
					this = x._ptr;
				return (*this);
			}
			T*	getPtr() const { return (_ptr); }
			T&	operator*() const { return (*_ptr); }
			T*	operator->() const { return (_ptr); }

			bool operator==(const const_reverse_iterator &it) { return (it._ptr == this->_ptr); }
			bool operator!=(const const_reverse_iterator &it) { return (it._ptr == this->_ptr); }
			bool operator<=(const const_reverse_iterator &it) { return (it._ptr >= this->_ptr); }
			bool operator>=(const const_reverse_iterator &it) { return (it._ptr <= this->_ptr); }
			bool operator<(const const_reverse_iterator &it) { return (it._ptr > this->_ptr); }
			bool operator>(const const_reverse_iterator &it) { return (it._ptr < this->_ptr); }
			
			const_reverse_iterator&	operator++() { _ptr--; return (*this); }
			const_reverse_iterator	operator++(int) { const_reverse_iterator tmp(this->_ptr); this->_ptr--; return (tmp); }
			const_reverse_iterator&	operator--() { _ptr++; return (*this); }
			const_reverse_iterator	operator--(int) { const_reverse_iterator tmp(this->_ptr); this->_ptr++; return (tmp); }
			
			const_reverse_iterator&	operator+=(const const_reverse_iterator &y)
			{
				this->_ptr = this->_ptr + y._ptr;
				return (*this);
			}
			
			const_reverse_iterator&	operator-=(const const_reverse_iterator &y)
			{
				this->_ptr = this->_ptr + y._ptr;
				return (*this); 
			}

			/*			Non-members operators overloads			*/
			friend const_reverse_iterator	operator+(int nb, const const_reverse_iterator &x)
			{
				const_reverse_iterator newIt(x);
				return (newIt += nb);
			}
			
			friend const_reverse_iterator	operator-(int nb, const const_reverse_iterator &x)
			{
				const_reverse_iterator newIt(x);
				return (newIt -= nb);
			}
		};		
	};
};

#endif
