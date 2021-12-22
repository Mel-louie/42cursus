/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:06:28 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/22 19:09:35 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

#include <vector>
#include <iostream>
#include <iterator>
#include "containers/vector.hpp"
#include "containers/utilities.hpp"
#include "iterators/iterator_traits.hpp"
#include "iterators/random_access_iterator.hpp"
#include "iterators/reverse_iterators.hpp"
#include "templates/algorithm.hpp"
#include "templates/utility.hpp"

void    vectorConstructors()
{
	std::cout << "<----- VECTOR::CONSTRUCTORS ----->" << std::endl;
	std::cout << std::endl;
	TESTED_NAMESPACE::vector<int>	first;
	TESTED_NAMESPACE::vector<int>	second(5, 42);
//	TESTED_NAMESPACE::vector<int>	third(second.begin(), second.end());
	TESTED_NAMESPACE::vector<int>	forth(second);

// the iterator constructor can also be used to construct from arrays:
	int intArr[] = {16,2,77,29};
	TESTED_NAMESPACE::vector<int> fifth(intArr, intArr + sizeof(intArr) / sizeof(int) );

	std::cout << _END << "first: "; printVec(first);
	std::cout << "second: "; printVec(second);
//	std::cout << "third: "; printVec(third);
	std::cout << "forth: "; printVec(forth);
//	std::cout << "fifth: "; printVec(fifth);
	std::cout << std::endl;

}

void	vectorAssign()
{
	std::cout << "<----- VECTOR::OPERATOR=() ----->" << std::endl;
	std::cout << std::endl;
	TESTED_NAMESPACE::vector<int>	first(3,0);
	TESTED_NAMESPACE::vector<int>	second(5, 42);
	
	second = first;
	first = TESTED_NAMESPACE::vector<int>();

	std::cout << "Size of first: " << int(first.size()) << std::endl;
	std::cout << "Size of second: " << int(second.size()) << std::endl;
	std::cout << std::endl;
}

void	vectorBegin()
{
	TESTED_NAMESPACE::vector<int> myvector;

	for (int i = 1 ; i <= 5; i++ )
		myvector.push_back(i);

	TESTED_NAMESPACE::vector<int>::iterator it = myvector.begin();
	std::cout << ' ' << *it << std::endl;
}

void	vectorEnd()
{
	TESTED_NAMESPACE::vector<int> myvector;

	for (int i = 1 ; i <= 5; i++ )
		myvector.push_back(i);

	TESTED_NAMESPACE::vector<int>::iterator it = myvector.end();
	--it;
	std::cout << ' ' << *it << std::endl;
}

void    testVector()
{
	// vectorConstructors();
	// vectorAssign();
	// vectorBegin();
	vectorEnd();
}

#endif