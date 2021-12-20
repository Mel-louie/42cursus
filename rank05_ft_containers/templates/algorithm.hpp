/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:04:59 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/20 15:56:39 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

namespace ft
{
	/*--------------------------------------------------------*/
	/*----------- FT::LEXICOGRAPHICAL_COMPARE ----------------*/
/*
*	Returns true if the range [first1,last1) compares lexicographically
*	less than the range [first2,last2)
*
*	@param comp	Binary function that accepts two arguments of the types pointed
*		by the iterators, and returns a value convertible to bool. The value returned
*		indicates whether the first argument is considered to go before the second
*		in the specific strict weak ordering it defines.
*		The function shall not modify any of its arguments.
*		This can either be a function pointer or a function object.
*/
	template<class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
	{
		for (; first1 != last1 ; ++first1, ++first2)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			if (*first1 < *first2)
				return (true);
		}
		return (first1 != last1);
	}

	template<class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2,
								Compare comp)
	{
		for (; first2 != last2 ; ++first1, ++first2)
		{
			if (first1 == last1 || comp(*first1, *first2))
				return (true);
			if (comp(*first2, *first1))
				return (false);
		}
		return (false);
	}
	
	/*--------------------------------------------------------*/
	/*---------------------- FT::EQUAL -----------------------*/
/*
*	test whether the elements in two ranges are equal
*
*	@param pred Binary function that accepts two elements as
*		argument (one of each of the two sequences, in the same order),
*		and returns a value convertible to bool. The value returned
*		indicates whether the elements are considered to match in the 
*		context of this function.
*/
	template<class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2)
	{
		for (; first1 != last1 ; ++first1, ++first2)
		{
			if (*first1 != *first2)
				return (false);
		}
		return (true);
	}
	
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2, BinaryPredicate pred)
	{
		for (; first1 != last1 ; ++first1, ++first2)
		{
			if (pred(*first1, *first2))
				return (false);
		}
		return (true);
	}
	
};

#endif