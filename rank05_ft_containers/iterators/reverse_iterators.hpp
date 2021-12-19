/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterators.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:34:57 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/19 19:10:11 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATORS_HPP
# define REVERSE_ITERATORS_HPP

# include "iterator_traits.hpp"
# include "random_access_iterator.hpp"
# include <iterator>

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


namespace ft
{
    template <typename T>
    class reverseIterator: public randomAccess<T>
	{
	protected:
		T*	_ptr;
	public:
        typedef	std::ptrdiff_t					difference_type;	// ptrdiff_t: Result of pointer subtraction
		typedef	T								value_type;
		typedef T*								pointer;
		typedef	T&								reference;
		typedef	std::random_access_iterator_tag	iterator_category;
        typedef	size_t	                        size_type;
        typedef reverseIterator<T>				it_class;
        
		it_class&	operator++() { _ptr--; return (*this); }									// prefix increment operator: --it
		it_class	operator++(int) { it_class tmp(this->_ptr); this->_ptr--; return (tmp); }	// postfix increment operator: it--
		it_class&	operator--() { _ptr++; return (*this); }									// prefix decrement operator: --it
		it_class	operator--(int) { it_class tmp(this->_ptr); this->_ptr++; return (tmp); }	// postfix decrement operator: it--
	};
};

#endif