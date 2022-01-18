/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:34:50 by mel-louie         #+#    #+#             */
/*   Updated: 2022/01/18 10:41:20 by louielouie       ###   ########.fr       */
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

namespace ft {

	struct	random_access_iterator_tag { };
	struct	input_iterator_tag { };
	struct	output_iterator_tag { };
	struct	forward_iterator_tag { };
	struct	bidirectional_iterator_tag{ };

	template<class iterator>
	struct iterator_traits {

		// member types
		typedef typename iterator::difference_type		difference_type;
		typedef typename iterator::value_type			value_type;
		typedef typename iterator::pointer				pointer;
		typedef typename iterator::reference			reference;
		typedef typename iterator::iterator_category	iterator_category;
	
	};

	template<class T>
	struct iterator_traits<T*> {

		// member types
		typedef std::ptrdiff_t							difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef ft::random_access_iterator_tag			iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*> {

		// member types
		typedef std::ptrdiff_t							difference_type;
		typedef T										value_type;
		typedef const T*								pointer;
		typedef const T&								reference;
		typedef ft::random_access_iterator_tag			iterator_category;
	};

	template<class InputIt>
	typename ft::iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last) {

		typename ft::iterator_traits<InputIt>::difference_type count;

		count = 0;
		while (first != last)
		{
			first++;
			count++;
		}
		return (count);
	};

	template<
		class Category, class T, class Distance = long int,
		class Pointer = T*, class Reference = T&>
	class iterator {

		public:
			typedef Category			iterator_category;
			typedef T					value_type;
			typedef Distance			difference_type;
			typedef Pointer				pointer;
			typedef Reference			reference;

	};
}

#endif