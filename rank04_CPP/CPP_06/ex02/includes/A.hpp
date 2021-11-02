/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:47:10 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/02 22:04:06 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP

# include "Base.hpp"

class A: public Base
{
public:
	A( void );
	A( A const& cpy);
	~A( void );

	A	&operator=( A const& src);
};

# endif
