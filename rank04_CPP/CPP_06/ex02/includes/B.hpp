/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:47:10 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/02 22:11:50 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

# include "Base.hpp"
# include <iostream>
# include <string>

class B: public Base
{
public:
	B( void );
	B( B const& cpy);
	~B( void );

	B	&operator=( B const& src);
};

# endif
