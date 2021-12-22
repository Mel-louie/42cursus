/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:34:57 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/22 15:27:06 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"
# include <iterator>

namespace ft
{
    template <typename T>
    class randomAccess
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
        typedef randomAccess<T>					it_class;

		randomAccess 	() { _ptr = NULL;}
		randomAccess	    (pointer x ) { _ptr = x; }
		randomAccess		(const randomAccess &cpy) { _ptr = cpy.getPtr(); }
		~randomAccess	() {}
		it_class&	operator=(const it_class &x)
		{
			if (this != x._ptr)
				this = x._ptr;
			return (*this);
		}
		
        reference	operator*() const { return (*_ptr); }
		pointer	    operator->() const { return (_ptr); }
		reference	operator[](size_type n) { return (*(_ptr + n)); }
		
		// /*
		// *	Return a reference to vector_iterator + i
		// *	Undefined behavior if the reference returned is out of container's range
		// */
		// reference operator[](unsigned int &i) const
		// {
		// 	value_type *tmp(this->_ptr);

		// 	if (i < 0)
        //         i *= -1;
        //     for (; i > 0; --i)
        //         tmp += i;
		// 	return (*tmp);
		// }


        bool operator==(const it_class &it) { return (it._ptr == this->_ptr); }		
        bool operator!=(const it_class &it) { return (it._ptr == this->_ptr); }
		bool operator<=(const it_class &it) { return (it._ptr >= this->_ptr); }
		bool operator>=(const it_class &it) { return (it._ptr <= this->_ptr); }
		bool operator<(const it_class &it) { return (it._ptr > this->_ptr); }
		bool operator>(const it_class &it) { return (it._ptr < this->_ptr); }

        
		it_class&	operator++() { _ptr++; return (*this); }									// prefix increment operator: --it
		it_class	operator++(int) { it_class tmp(this->_ptr); this->_ptr++; return (tmp); }	// postfix increment operator: it--
		it_class&	operator--() { _ptr--; return (*this); }									// prefix decrement operator: --it
		it_class	operator--(int) { it_class tmp(this->_ptr); this->_ptr--; return (tmp); }	// postfix decrement operator: it--
		
		it_class&	operator+=(const it_class &y)
		{
			this->_ptr = this->_ptr + y._ptr;
			return (*this);
		}
		
		it_class	&	operator-=(const it_class &y)
		{
			this->_ptr = this->_ptr - y._ptr;
			return (*this); 
		}

	/*		            	Getter          			*/
		pointer	    getPtr() const { return (_ptr); }

	/*			Non-members operators overloads			*/
		friend it_class		operator+(int nb, const it_class	 &x)
		{
			it_class	 newIt(x);
			return (newIt += nb);
		}
		
		friend it_class		operator-(int nb, const it_class	 &x)
		{
			it_class	 newIt(x);
			return (newIt -= nb);
		}
	};
}
#endif