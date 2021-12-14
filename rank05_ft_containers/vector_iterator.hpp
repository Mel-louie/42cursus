/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:24:04 by mdesfont          #+#    #+#             */
/*   Updated: 2021/12/14 10:37:40 by mel-louie        ###   ########.fr       */
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
	
	/*							Coplien's form				*/

		iterator(int *x): _ptr(x) {}
		iterator(const iterator &mit): _ptr(mit.p) {}
		~iterator() {}
		
	/*
	*	Assignation operator. Both iterator will point to the same T element
    *   @param x 	the itaration that will be assign
	*/
		iterator	(const iterator &x)
		{
			if (this != x._ptr)
				this = x._ptr;
			return (*this);
		}

	/*							Operators overloads			*/
		T&	operator*() const { return (*_ptr); }
		T*	operator->() const { return (_ptr); }

		bool operator==(const iterator &it) { return (it._ptr == _ptr); }
		bool operator!=(const iterator &it) { return (it._ptr == _ptr); }
		iterator&	operator++() { _ptr++; return (*this); }									// prefix increment operator: --it
		iterator	operator++(int) { iterator tmp(this->_ptr); this->_ptr++; return (tmp); }	// postfix increment operator: it--
		iterator&	operator--() { _ptr--; return (*this); }									// prefix decrement operator: --it
		iterator	operator--(int) { iterator tmp(this->_ptr); this->_ptr--; return (tmp); }	// postfix decrement operator: it--
	
	};
}

#endif
