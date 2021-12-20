/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:49:18 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/20 16:14:54 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft
{
	/*--------------------------------------------------------*/
	/*---------------------- FT::PAIR ------------------------*/
	template<class T1, class T2>
	struct pair
	{
		T1	first;
		T2	second;

/*					Consts & Dests					*/
		pair(): first(), second() {};

	/*
	*	Copy constructor
	*	@param pr the object that will be copied
	*/
		template<class U, class V>
		pair	(const pair<U,V> &pr): first(pr.first), second(pr.second) {};

	/*
	*	Initialization constructor
	*	member first is constructed with a and member second with b
	*/
		pair	(const T1& a, const T2& b): first(a), second(b) {};
		
		~pair();

	/*
	*	assigns pr as the new content for the pair object
	*/
		pair&	operator=(const pair &pr)
		{
			if (this != pr)
			{
				first = pr.first;
				second = pr.second;
			}
			return (*this);
		};
	};
	
	template <class T1, class T2>
  pair<T1,T2> make_pair (T1 x, T2 y);
};

#endif