/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:06:28 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/22 17:37:49 by mel-louie        ###   ########.fr       */
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
	TESTED_NAMESPACE::vector<int>   first;
	TESTED_NAMESPACE::vector<int>   second(5, 42);
//	TESTED_NAMESPACE::vector<int>   third(second.begin(), second.end());
	TESTED_NAMESPACE::vector<int>   forth(second);

	std::cout << "first: "; printVec(first);
	std::cout << "second: "; printVec(second);
//	std::cout << "third: "; printVec(third);
	std::cout << "forth: "; printVec(forth);
//	std::cout << third.size() << std::endl;

// 	int myints[] = {16,2,77,29};
//   TESTED_NAMESPACE::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

//   std::cout << "The contents of fifth are:";
//   for (TESTED_NAMESPACE::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

}

void    testVector()
{
    vectorConstructors();
}

#endif