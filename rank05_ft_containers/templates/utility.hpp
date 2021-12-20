/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:49:18 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/20 16:00:01 by mel-louie        ###   ########.fr       */
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
		pair	(const pair<U,V> &pr): first(pr.first), second() {};
	};
	
};

#endif