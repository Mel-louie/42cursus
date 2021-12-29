/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:34:50 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/29 18:35:04 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <iterator>

/*
*	Distance
*		Type to represent the difference between two iterators.
*	T
*		Type of elements pointed by the iterator.
*	Pointer
*		Type to represent a pointer to an element pointed by the iterator.
*	Reference
*		Type to represent a reference to an element pointed by the iterator.
*	Category
*		Category to which the iterator belongs to. It must be one of the following iterator tags:
*		iterator tag				Category of iterators
*		input_iterator_tag			Input Iterator
*		output_iterator_tag			Output Iterator
*		forward_iterator_tag		Forward Iterator
*		bidirectional_iterator_tag	Bidirectional Iterator
*		iterators_tag	Random-access Iterator
* https://www.cplusplus.com/reference/iterator/iterator_traits/
*/

namespace ft
{
	template <class Iterator> struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T> struct iterator_traits<T*>
	{
		typedef	std::ptrdiff_t							difference_type;	// ptrdiff_t: Result of pointer subtraction
		typedef	T										value_type;
		typedef T*										pointer;
		typedef	T&										reference;
		typedef	std::random_access_iterator_tag			iterator_category;
	};

	template <class T> struct iterator_traits<const T*>
	{
		typedef	std::ptrdiff_t							difference_type;	// ptrdiff_t: Result of pointer subtraction
		typedef	T										value_type;
		typedef const T*								pointer;
		typedef	const T&								reference;
		typedef	std::random_access_iterator_tag			iterator_category;
	};
}

#endif