/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:47:10 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/02 22:04:13 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

# include "Base.hpp"

class C: public Base
{
public:
	C( void );
	C( C const& cpy);
	~C( void );

	C	&operator=( C const& src);
};

# endif
