/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:17:26 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/29 15:58:10 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_TRAITS_HPP
# define TYPES_TRAITS_HPP


namespace ft
{
	// Ref: https://www.cplusplus.com/reference/type_traits/integral_constant/?kw=integral_constant
	template <typename T, T Val>
	struct integral_constant
	{
		typedef integral_constant	type;
		typedef T					value_type;
		enum { value = Val };
	};
	typedef integral_constant< bool, true >  true_type;
	typedef integral_constant< bool, false > false_type;

	// Ref: https://www.cplusplus.com/reference/type_traits/is_same/?kw=is_same
	template < typename T, typename U > struct is_same : public false_type {};
	template < typename T > struct is_same< T, T > : public true_type {};

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
	template<class T>
	struct is_integral { static const bool value = false; };

	template<>
	struct is_integral<bool> { static const bool value = true; };

	template<>
	struct is_integral<char> { static const bool value = true; };
	
	template<>
	struct is_integral<unsigned char> { static const bool value = true; };

	template<>
	struct is_integral<wchar_t> { static const bool value = true; };

	template<>
	struct is_integral<short> { static const bool value = true; };

	template<>
	struct is_integral<unsigned short> { static const bool value = true; };

	template<>
	struct is_integral<int> { static const bool value = true; };

	template<>
	struct is_integral<unsigned int> { static const bool value = true; };

	template<>
	struct is_integral<long> { static const bool value = true; };

	template<>
	struct is_integral<unsigned long> { static const bool value = true; };

	template<>
	struct is_integral<long long> { static const bool value = true; };

	template<>
	struct is_integral<unsigned long long> { static const bool value = true; };

};

#endif