/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traits.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:17:26 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/20 14:29:56 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAITS_HPP
# define TRAITS_HPP

/*
*	enable type if condition is met
*	the type T is enabled as member type enable_if::type if Cond is true.
*/
template<bool Cond, class T = void>
struct enable_if {} ;

template<>

#endif