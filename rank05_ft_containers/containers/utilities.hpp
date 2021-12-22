/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:53:33 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/21 18:05:12 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef utilities_HPP
# define utilities_HPP

# include "vector.hpp"
# include <iostream>
# include <string>

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE  //change to ft or stl in the makefile to change it
#endif

const std::string _RED	= "\033[31m";
const std::string _GRN	= "\033[32m";
const std::string _YLW	= "\033[33m";
const std::string _BLU	= "\033[34m";
const std::string _END	= "\033[0m";
const std::string B_BLACK		= "\033[1;30m"
const std::string B_RED		= "\033[1;31m"
const std::string B_GREEN		= "\033[1;32m"
const std::string B_YELLOW	= "\033[1;33m"
const std::string B_BLUE		= "\033[1;34m"
const std::string B_PURPLE	= "\033[1;35m"
B_CYAN		= "\033[1;36m"
B_WHITE		= "\033[1;37m"

template<typename T>
void    utilities(TESTED_NAMESPACE::vector<T> &v)
{
	std::cout << "{";
	size_t  last = v.size() - 1;
	std::cout << _GRN;
	for (size_t i = 0 ; i < v.size() ; ++i)
	{
		std::cout << v[i];
		if (i != last)
			std::cout << ", ";
	}
	std::cout << _END;
	std::cout << "}" << std::endl;
}

#endif