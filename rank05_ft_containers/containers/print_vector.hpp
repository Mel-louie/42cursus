/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vector.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:53:33 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/21 17:38:41 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_VECTOR_HPP
#define PRINT_VECTOR_HPP

#include "vector.hpp"
#include <iostream>
#include <string>

const std::string _RED	= "\033[31m";
const std::string _GRN	= "\033[32m";
const std::string _YLW	= "\033[33m";
const std::string _BLU	= "\033[34m";
const std::string _END	= "\033[0m";

template<typename T>
void    print_vector(FT::vector<T> &v)
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