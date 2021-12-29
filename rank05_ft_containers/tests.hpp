/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:06:28 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/29 17:16:03 by mel-louie        ###   ########.fr       */
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
// #include "iterators/random_access_iterator.hpp"
// #include "iterators/reverse_iterators.hpp"
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
//	int intArr[] = {16,2,77,29};
//	TESTED_NAMESPACE::vector<int> fifth(intArr, intArr + sizeof(intArr) / sizeof(int) );

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

	printVec(first);
	std::cout << "Size of first: " << int(first.size()) << std::endl;
	printVec(second);
	std::cout << "Size of second: " << int(second.size()) << std::endl;
	std::cout << std::endl;
}

void	vectorBegin()
{
	std::cout << "<----- VECTOR::BEGIN() ----->" << std::endl;
	std::cout << std::endl;
	TESTED_NAMESPACE::vector<int> myvector;

	for (int i = 1 ; i <= 5; i++ )
		myvector.push_back(i);

	TESTED_NAMESPACE::vector<int>::iterator it = myvector.begin();
	printVec(myvector);
	std::cout << ' ' << *it << std::endl;
	std::cout << std::endl;
}

void	vectorEnd()
{
	std::cout << "<----- VECTOR::END() ----->" << std::endl;
	std::cout << std::endl;
	TESTED_NAMESPACE::vector<int> myvector;

	for (int i = 1 ; i <= 5; i++ )
		myvector.push_back(i);

	TESTED_NAMESPACE::vector<int>::iterator it = myvector.end();
	--it;
	printVec(myvector);
	std::cout << ' ' << *it << std::endl;
	std::cout << std::endl;
}

void	vectorRbegin()
{
	std::cout << "<----- VECTOR::RBEGIN() ----->" << std::endl;
	std::cout << std::endl;
	TESTED_NAMESPACE::vector<std::string> myvector;
	
	myvector.push_back("Hello");
	myvector.push_back("how");
	myvector.push_back("are");
	myvector.push_back("you?");

	TESTED_NAMESPACE::vector<std::string>::reverse_iterator rev_it = myvector.rbegin();

	std::cout << *rev_it << std::endl;
	++rev_it;
	std::cout << *rev_it << std::endl;

	printVec(myvector);
	std::cout << std::endl;
}

void	vectorRend()
{
	std::cout << "<----- VECTOR::REND() ----->" << std::endl;
	std::cout << std::endl;
	TESTED_NAMESPACE::vector<std::string> myvector;
	
	myvector.push_back("Hello");
	myvector.push_back("how");
	myvector.push_back("are");
	myvector.push_back("you?");

	TESTED_NAMESPACE::vector<std::string>::reverse_iterator rev_it = myvector.rend();

	std::cout << *rev_it << std::endl;
	--rev_it;
	std::cout << *rev_it << std::endl;

	printVec(myvector);
	std::cout << std::endl;
}

void	vectorSize()
{
	std::cout << "<----- VECTOR::SIZE() ----->" << std::endl;
	std::cout << std::endl;
	TESTED_NAMESPACE::vector<int> myints;
	std::cout << "0. size: " << myints.size() <<  std::endl;

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() <<  std::endl;

	myints.insert (myints.end(),10,100);
	std::cout << "2. size: " << myints.size() <<  std::endl;

	myints.pop_back();
	std::cout << "3. size: " << myints.size() <<  std::endl;
	std::cout << std::endl;
}

void	vectorMaxSize()
{
	std::cout << "<----- VECTOR::MAXSIZE() ----->" << std::endl;
	std::cout << std::endl;
	TESTED_NAMESPACE::vector<int> myvector;

	// set some content in the vector:
	for (int i = 0 ; i < 100 ; i++) myvector.push_back(i);
	std::cout << "max_size: " << myvector.max_size() <<  std::endl;
	std::cout << std::endl;
}

void	vectorResize()
{
	std::cout << "<----- VECTOR::RESIZE() ----->" << std::endl;
	std::cout << std::endl;
	TESTED_NAMESPACE::vector<int> myvector;
	
	for (int i = 0 ; i < 100 ; i++) myvector.push_back(i);
	printVec(myvector);
	myvector.resize(5);
	printVec(myvector);
	myvector.resize(8, 100);
	printVec(myvector);
	myvector.resize(12);
	printVec(myvector);
	std::cout << std::endl;
}

void	vectorCapacity()
{
	std::cout << "<----- VECTOR::CAPACITY() ----->" << std::endl;
	std::cout << std::endl;
	TESTED_NAMESPACE::vector<int> myvector;

	for (int i = 0 ; i < 100 ; i++) myvector.push_back(i);
	std::cout << "capacity: " << myvector.capacity() << std::endl;
	std::cout << std::endl;
}

void	vectorEmpty()
{
	std::cout << "<----- VECTOR::EMPTY() ----->" << std::endl;
	std::cout << std::endl;
	TESTED_NAMESPACE::vector<int> myvector;
	int sum (0);

	for (int i = 0 ; i < 100 ; i++) myvector.push_back(i);

	while (!myvector.empty())
	{
		sum++;
		myvector.pop_back();
	}
	std::cout << "sum is increment until myvector is empty, total sum: " << sum <<  std::endl;
	std::cout << std::endl;
}

void	vectorReserve()
{
	std::cout << "<----- VECTOR::RESERVE() ----->" << std::endl;
	std::cout << std::endl;
	TESTED_NAMESPACE::vector<int>::size_type sz;
	TESTED_NAMESPACE::vector<int> bar;

	sz = bar.capacity();
	std::cout << "capacity at the begining: " << sz <<  std::endl;
	
	bar.reserve(100);
	for (int i = 0 ; i < 100 ; ++i)
	{
	   	bar.push_back(i);
		if (sz != bar.capacity())
		{
			sz = bar.capacity();
      		std::cout << "capacity at the end: " << sz <<  std::endl;
		}
	}
	std::cout << std::endl;
}

void	vectorBrackets()
{
	std::cout << "<----- VECTOR::OPERATOR[]() ----->" << std::endl;
	std::cout << std::endl;
	TESTED_NAMESPACE::vector<int> vec(10); //vector of 10 elements, at 0
	TESTED_NAMESPACE::vector<int>::size_type size = vec.size();

	// assign some values
	for (size_t i = 0 ; i < size ; i++) vec[i] = i;
	
	// reverse vector, using operator[]
	for (size_t i = 0 ; i < size / 2 ; i++)
	{
		int tmp;
		tmp = vec[size - 1 - i];
		vec[size - 1 - i] = vec[i];
		vec[i] = tmp;
	}
	printVec(vec);
	std::cout << std::endl;
}

void	vectorAt()
{
	std::cout << "<----- VECTOR::AT() ----->" << std::endl;
	std::cout << std::endl;
	TESTED_NAMESPACE::vector<int> vec(10); //vector of 10 elements, at 0
	TESTED_NAMESPACE::vector<int>::size_type size = vec.size();

	// assign some values
	for (size_t i = 0 ; i < size ; i++) vec.at(i) = i;
	printVec(vec);
	std::cout << std::endl;
}

void	vectorFront()
{
	std::cout << "<----- VECTOR::FRONT() ----->" << std::endl;
	std::cout << std::endl;
	TESTED_NAMESPACE::vector<int> vec;
	printVec(vec);

	vec.push_back(42);
	vec.push_back(21);
	std::cout << vec.front() << std::endl;
	printVec(vec);
	std::cout << std::endl;
}

void	vectorBack()
{
	std::cout << "<----- VECTOR::BACK() ----->" << std::endl;
	std::cout << std::endl;
	TESTED_NAMESPACE::vector<int> vec;
	printVec(vec);

	vec.push_back(42);
	vec.push_back(21);
	std::cout << vec.back() << std::endl;
	printVec(vec);
	std::cout << std::endl;
}

void    testVector()
{
	// vectorConstructors();
	// vectorAssign();
	// vectorBegin();
	// vectorEnd();
	// vectorRbegin();
	// vectorRend();
	// vectorSize();
	// vectorMaxSize();
	// vectorResize();
	// vectorCapacity();
	// vectorEmpty();
	// vectorReserve();
	// vectorBrackets();
	// vectorAt();
	// vectorFront();
	// vectorBack();
	
}

#endif