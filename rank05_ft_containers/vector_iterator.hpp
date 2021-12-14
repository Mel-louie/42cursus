/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:24:04 by mdesfont          #+#    #+#             */
/*   Updated: 2021/12/14 12:17:05 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iostream>
# include <string>

namespace	ft
{
	/*--------------------------------------------------------*/
	/*----------------- FT::VECTOR_ITERATOR ------------------*/
	/*
    *   @param T        Type of container's elements.
    *   @param Alloc    Object used to manage the vector' storage.
	*/

	template <typename T>
	class iterator
	{

	/*							Attributes					*/
	private:
		T	*_ptr;

	public:
	/*							Aliases						*/
		
	
	/*							Coplien's form				*/

		iterator(int *x): _ptr(x) {}
	/*
	*	Copy constructor
	*	@param cpy 	the object that will be copied
	*/
		iterator	(const iterator &cpy) { _ptr = cpy.getPtr(); }
		~iterator() {}
	/*
	*	Assignation operator. Both iterator will point to the same T element
	*	@param x 	the iteration that will be assigned
	*/
		iterator&	operator=(const iterator &x)
		{
			if (this != x._ptr)
				this = x._ptr;
			return (*this);
		}
		
	/*							Getter						*/
		T*	getPtr() const { return (_ptr); }

	/*							Operators overloads			*/
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
}

#endif
