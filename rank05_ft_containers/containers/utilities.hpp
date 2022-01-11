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
# include "stack.hpp"
# include <iostream>
# include <string>
# include <sys/time.h>
# include <stack>

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE  //change to ft or stl in the makefile to change it
#endif

const std::string _BLCK	= "\033[30m";
const std::string _RED	= "\033[31m";
const std::string _GRN	= "\033[32m";
const std::string _YLW	= "\033[33m";
const std::string _BLU	= "\033[34m";
const std::string _CYA	= "\033[36m";
const std::string _END	= "\033[0m";
const std::string B_RD	= "\033[1;31m";
const std::string B_GRN	= "\033[1;32m";
const std::string B_YLW	= "\033[1;33m";
const std::string B_BLU	= "\033[1;34m";
const std::string B_WHT	= "\033[1;37m";
const std::string BK_WI = "\033[47m";

template<typename T>
void    printVec(TESTED_NAMESPACE::vector<T> &v)
{
	size_t  last = v.size() - 1;

	std::cout << "{" << _GRN;
	for (size_t i = 0 ; i < v.size() ; ++i)
	{
		std::cout << v[i];
		if (i != last)
			std::cout << ", ";
	}
	std::cout << _END;
	std::cout << "}" << std::endl;
};

template<typename T>
void	printStack(TESTED_NAMESPACE::stack<T> &s)
{
	TESTED_NAMESPACE::stack<T> tmp;
	size_t last = s.size();
	size_t i = 1;

	std::cout << "{" << _CYA;
	while (!s.empty())
	{
		T	top = s.top();
		s.pop();
		std::cout << top;
		if (i != last)
			std::cout << ", ";
		tmp.push(top);
		i++;
	}
	std::cout << _END;
	std::cout << "}" << std::endl;
	while (!tmp.empty())
	{
		T	top = tmp.top();
		tmp.pop();
		s.push(top);
	}
};

#endif