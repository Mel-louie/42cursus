/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traits.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:17:26 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/20 14:44:40 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAITS_HPP
# define TRAITS_HPP


namespace ft
{

	/*--------------------------------------------------------*/
	/*------------------- FT::ENABLE_IF ----------------------*/
/*
*	enable type if condition is met
*	the type T is enabled as member type enable_if::type if Cond is true.
*/
	template<bool Cond, class T = void>
	struct	enable_if {} ;

	template<class T>
	struct	enable_if<true, T> { typedef T type; };

	/*--------------------------------------------------------*/
	/*----------------- FT::IS_INTEGRAL ----------------------*/
/*
*	trait class that identifies whether T is an integral type
*	if yes, value is true
*/
	template <class T>
	struct is_integral { static const bool value = false } ;

};

#endif