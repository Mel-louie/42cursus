/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:06:28 by mel-louie         #+#    #+#             */
/*   Updated: 2022/01/11 11:44:56 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include "containers/vector.hpp"
#include "containers/stack.hpp"
#include "containers/map.hpp"
#include "containers/utilities.hpp"
#include "iterators/iterator_traits.hpp"
#include "templates/algorithm.hpp"
#include "templates/utility.hpp"
#include "iterators/map_iterators.hpp"
#include "containers/rb_tree.hpp"

/*---------------------------------- vector --------------------------------*/

// void    vectorConstructors()
// {
// 	std::cout << "<----- VECTOR::CONSTRUCTORS ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int>	first;
// 	TESTED_NAMESPACE::vector<int>	second(5, 42);
// 	TESTED_NAMESPACE::vector<int>	third(second.begin(), second.end());
// 	TESTED_NAMESPACE::vector<int>	forth(second);

// // the iterator constructor can also be used to construct from arrays:
// 	int intArr[] = {16,2,77,29};
// 	TESTED_NAMESPACE::vector<int> fifth(intArr, intArr + sizeof(intArr) / sizeof(int) );

// 	std::cout << _END << "first: "; printVec(first);
// 	std::cout << "second: "; printVec(second);
// 	std::cout << "third: "; printVec(third);
// 	std::cout << "forth: "; printVec(forth);
// 	std::cout << "fifth: "; printVec(fifth);
// 	std::cout << std::endl;
// }

// void	vectorAssignation()
// {
// 	std::cout << "<----- VECTOR::OPERATOR=() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int>	first(3,0);
// 	TESTED_NAMESPACE::vector<int>	second(5, 42);
	
// 	second = first;
// 	first = TESTED_NAMESPACE::vector<int>();

// 	printVec(first);
// 	std::cout << "Size of first: " << int(first.size()) << std::endl;
// 	printVec(second);
// 	std::cout << "Size of second: " << int(second.size()) << std::endl;
// 	std::cout << std::endl;
// }

// void	vectorBegin()
// {
// 	std::cout << "<----- VECTOR::BEGIN() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> myvector;

// 	for (int i = 1 ; i <= 5; i++ )
// 		myvector.push_back(i);

// 	TESTED_NAMESPACE::vector<int>::iterator it = myvector.begin();
// 	printVec(myvector);
// 	std::cout << ' ' << *it << std::endl;
// 	std::cout << std::endl;
// }

// void	vectorEnd()
// {
// 	std::cout << "<----- VECTOR::END() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> myvector;

// 	for (int i = 1 ; i <= 5; i++ )
// 		myvector.push_back(i);

// 	TESTED_NAMESPACE::vector<int>::iterator it = myvector.end();
// 	--it;
// 	printVec(myvector);
// 	std::cout << ' ' << *it << std::endl;
// 	std::cout << std::endl;
// }

// void	vectorRbegin()
// {
// 	std::cout << "<----- VECTOR::RBEGIN() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<std::string> myvector;
	
// 	myvector.push_back("Hello");
// 	myvector.push_back("how");
// 	myvector.push_back("are");
// 	myvector.push_back("you?");

// 	TESTED_NAMESPACE::vector<std::string>::reverse_iterator rev_it = myvector.rbegin();

// 	std::cout << *rev_it << std::endl;
// 	++rev_it;
// 	std::cout << *rev_it << std::endl;

// 	printVec(myvector);
// 	std::cout << std::endl;
// }

// void	vectorRend()
// {
// 	std::cout << "<----- VECTOR::REND() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<std::string> myvector;
	
// 	myvector.push_back("Hello");
// 	myvector.push_back("how");
// 	myvector.push_back("are");
// 	myvector.push_back("you?");

// 	TESTED_NAMESPACE::vector<std::string>::reverse_iterator rev_it = myvector.rend();

// 	std::cout << *rev_it << std::endl;
// 	--rev_it;
// 	std::cout << *rev_it << std::endl;

// 	printVec(myvector);
// 	std::cout << std::endl;
// }

// void	vectorSize()
// {
// 	std::cout << "<----- VECTOR::SIZE() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> myints;
// 	std::cout << "0. size: " << myints.size() <<  std::endl;

// 	for (int i=0; i<10; i++) myints.push_back(i);
// 	std::cout << "1. size: " << myints.size() <<  std::endl;

// 	myints.insert (myints.end(),10,100);
// 	std::cout << "2. size: " << myints.size() <<  std::endl;

// 	myints.pop_back();
// 	std::cout << "3. size: " << myints.size() <<  std::endl;
// 	std::cout << std::endl;
// }

// void	vectorMaxSize()
// {
// 	std::cout << "<----- VECTOR::MAXSIZE() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> myvector;

// 	// set some content in the vector:
// 	for (int i = 0 ; i < 100 ; i++) myvector.push_back(i);
// 	std::cout << "max_size: " << myvector.max_size() <<  std::endl;
// 	std::cout << std::endl;
// }

// void	vectorResize()
// {
// 	std::cout << "<----- VECTOR::RESIZE() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> myvector;
	
// 	for (int i = 0 ; i < 100 ; i++) myvector.push_back(i);
// 	printVec(myvector);
// 	myvector.resize(5);
// 	printVec(myvector);
// 	myvector.resize(8, 100);
// 	printVec(myvector);
// 	myvector.resize(12);
// 	printVec(myvector);
// 	std::cout << std::endl;
// }

// void	vectorCapacity()
// {
// 	std::cout << "<----- VECTOR::CAPACITY() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> myvector;

// 	for (int i = 0 ; i < 100 ; i++) myvector.push_back(i);
// 	std::cout << "capacity: " << myvector.capacity() << std::endl;
// 	std::cout << std::endl;
// }

// void	vectorEmpty()
// {
// 	std::cout << "<----- VECTOR::EMPTY() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> myvector;
// 	int sum (0);

// 	for (int i = 0 ; i < 100 ; i++) myvector.push_back(i);

// 	while (!myvector.empty())
// 	{
// 		sum++;
// 		myvector.pop_back();
// 	}
// 	std::cout << "sum is increment until myvector is empty, total sum: " << sum <<  std::endl;
// 	std::cout << std::endl;
// }

// void	vectorReserve()
// {
// 	std::cout << "<----- VECTOR::RESERVE() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int>::size_type sz;
// 	TESTED_NAMESPACE::vector<int> bar;

// 	sz = bar.capacity();
// 	std::cout << "capacity at the begining: " << sz <<  std::endl;
	
// 	bar.reserve(100);
// 	for (int i = 0 ; i < 100 ; ++i)
// 	{
// 	   	bar.push_back(i);
// 		if (sz != bar.capacity())
// 		{
// 			sz = bar.capacity();
//       		std::cout << "capacity at the end: " << sz <<  std::endl;
// 		}
// 	}
// 	std::cout << std::endl;
// }

// void	vectorBrackets()
// {
// 	std::cout << "<----- VECTOR::OPERATOR[]() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> vec(10); //vector of 10 elements, at 0
// 	TESTED_NAMESPACE::vector<int>::size_type size = vec.size();

// 	// assign some values
// 	for (size_t i = 0 ; i < size ; i++) vec[i] = i;
	
// 	// reverse vector, using operator[]
// 	for (size_t i = 0 ; i < size / 2 ; i++)
// 	{
// 		int tmp;
// 		tmp = vec[size - 1 - i];
// 		vec[size - 1 - i] = vec[i];
// 		vec[i] = tmp;
// 	}
// 	printVec(vec);
// 	std::cout << std::endl;
// }

// void	vectorAt()
// {
// 	std::cout << "<----- VECTOR::AT() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> vec(10); //vector of 10 elements, at 0
// 	TESTED_NAMESPACE::vector<int>::size_type size = vec.size();

// 	// assign some values
// 	for (size_t i = 0 ; i < size ; i++) vec.at(i) = i;
// 	printVec(vec);
// 	std::cout << std::endl;
// }

// void	vectorFront()
// {
// 	std::cout << "<----- VECTOR::FRONT() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> vec;
// 	printVec(vec);

// 	vec.push_back(42);
// 	vec.push_back(21);
// 	std::cout << vec.front() << std::endl;
// 	printVec(vec);
// 	std::cout << std::endl;
// }

// void	vectorBack()
// {
// 	std::cout << "<----- VECTOR::BACK() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> vec;
// 	printVec(vec);

// 	vec.push_back(42);
// 	vec.push_back(21);
// 	std::cout << vec.back() << std::endl;
// 	printVec(vec);
// 	std::cout << std::endl;
// }

// void	vectorAssign()
// {
// 	std::cout << "<----- VECTOR::ASSIGN() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> vec1;
// 	TESTED_NAMESPACE::vector<int> vec2;
// 	TESTED_NAMESPACE::vector<int> vec3;

// 	vec1.assign(7, 100);
// 	printVec(vec1);

// 	TESTED_NAMESPACE::vector<int>::iterator it = vec1.begin();

// 	vec2.assign(it, vec1.end() - 1);	
// 	printVec(vec2);

// 	int	i[] = {15, 22, 4, 77};
// 	vec3.assign(i + 1, i + 4);	// assign from array
// 	printVec(vec3);

// 	std::cout << std::endl;
// }

// void	vectorPushPop()
// {
// 	std::cout << "<----- VECTOR::PUSH/POP_BACK() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> v;

// 	v.push_back(1);
// 	v.push_back(2);
// 	v.push_back(3);
// 	printVec(v);

// 	v.pop_back();
// 	v.pop_back();
// 	printVec(v);

// 	v.push_back(42);
// 	printVec(v);

// 	std::cout << std::endl;
// }

// void	vectorInsert()
// {
// 	std::cout << "<----- VECTOR::INSERT() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> v(3, 100);
// 	TESTED_NAMESPACE::vector<int>::iterator it;

// 	it = v.begin();
// 	it = v.insert(it, 200);
	
// 	v.insert(it, 2, 300);

// 	it = v.begin();
	
// 	TESTED_NAMESPACE::vector<int> v2(2, 600);
// 	v.insert(it + 2, v2.begin(), v2.end());

// 	printVec(v);
// 	std::cout << std::endl;
// }

// void	vectorErase()
// {
// 	std::cout << "<----- VECTOR::ERASE() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> vec;

// 	for (int i = 1 ; i != 10 ; ++i)
// 		vec.push_back(i);
// 	printVec(vec);
	
// 	// erase the 6th element
// 	vec.erase(vec.begin() + 5);
// 	printVec(vec);

// 	// erase the first 3 elements
// 	vec.erase(vec.begin(), vec.begin() + 3);

// 	printVec(vec);
// 	std::cout << std::endl;
// }


// void	vectorSwap()
// {
// 	std::cout << "<----- VECTOR::SWAP() ----->" << std::endl;
// 	std::cout << std::endl;

// 	TESTED_NAMESPACE::vector<int> foo(3, 100);
// 	TESTED_NAMESPACE::vector<int> bar(5, 200);
// 	std::cout << "foo contains:";
// 	for (unsigned i = 0; i < foo.size(); i++) std::cout << ' ' << foo[i];
// 	std::cout << std::endl;
// 	std::cout << "bar contains:";
// 	for (unsigned i = 0; i < bar.size(); i++) std::cout << ' ' << bar[i];
// 	std::cout << std::endl;
// 	std::cout << "[swap]" << std::endl; foo.swap(bar);
// 	std::cout << "foo contains:";
// 	for (unsigned i = 0; i < foo.size(); i++) std::cout << ' ' << foo[i];
// 	std::cout << std::endl;
// 	std::cout << "bar contains:";
// 	for (unsigned i = 0; i < bar.size(); i++) std::cout << ' ' << bar[i];

// 	std::cout << std::endl;
// 	std::cout << std::endl;
// }

// void	vectorClear()
// {
// 	std::cout << "<----- VECTOR::CLEAR() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> vec;

// 	for (int i = 100 ; i != 110 ; i++)
// 		vec.push_back(i);
	
// 	std::cout << "Vector before clear: "; printVec(vec);
// 	vec.clear();
// 	std::cout << "Vector after clear: "; printVec(vec);

// 	std::cout << std::endl;
// }

// void	vectorGetAllocator()
// {
// 	std::cout << "<----- VECTOR::GETALLOCATOR() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> myvector;
// 	int * p;
// 	unsigned int i;

// 	// allocate an array with space for 5 elements using vector's allocator:
// 	p = myvector.get_allocator().allocate(5);

// 	for (i = 0 ; i < 5 ; i++)
// 		myvector.push_back(i);

// 	std::cout << "The allocated array contains: "; printVec(myvector);

// 	// destroy and deallocate, if not, it leaks
// 	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
// 	myvector.get_allocator().deallocate(p,5);

// 	std::cout << std::endl;
// }

// void	vectorSwapNonMember()
// {
// 	std::cout << "<----- VECTOR::SWAP_NON_MEMBER() ----->" << std::endl;
// 	std::cout << std::endl;

// 	TESTED_NAMESPACE::vector<int> foo(3, 100);
// 	TESTED_NAMESPACE::vector<int> bar(5, 200);

// 	std::cout << "foo contains:";
// 	for (TESTED_NAMESPACE::vector<int>::iterator it = foo.begin() ; it != foo.end() ; ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << std::endl;
// 	std::cout << "bar contains:";
// 	for (TESTED_NAMESPACE::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << std::endl;
// 	std::cout << "[swap]" << std::endl; foo.swap(bar);
// 	std::cout << "foo contains:";
// 	for (TESTED_NAMESPACE::vector<int>::iterator it = foo.begin() ; it != foo.end() ; ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << std::endl;
// 	std::cout << "bar contains:";
// 	for (TESTED_NAMESPACE::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << std::endl;
// }

// void	vectorRelationalOperators()
// {
// 	std::cout << "<----- VECTOR::RELATIONAL_OPERATORS() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> v1(3, 100);
// 	TESTED_NAMESPACE::vector<int> v2(2, 200);
	
// 	if (v1 == v2) std::cout << "v1 and v2 are equal" << std::endl;
// 	if (v1 != v2) std::cout << "v1 and v2 aren't equal" << std::endl;
// 	if (v1 < v2) std::cout << "v1 is less than v2" << std::endl;
// 	if (v1 > v2) std::cout << "v1 is greater than v2" << std::endl;
// 	if (v1 <= v2) std::cout << "v1 is less than or equal to v2" << std::endl;
// 	if (v1 >= v2) std::cout << "v1 is greater than or equal to v2" << std::endl;

// 	std::cout << std::endl;
// }

// void    testVector()
// {
// 	vectorConstructors();
// 	vectorAssignation();
// 	vectorBegin();
// 	vectorEnd();
// 	vectorRbegin();
// 	vectorRend();
// 	vectorSize();
// 	vectorMaxSize();
// 	vectorResize();
// 	vectorCapacity();
// 	vectorEmpty();
// 	vectorReserve();
// 	vectorBrackets();
// 	vectorAt();
// 	vectorFront();
// 	vectorBack();
// 	vectorAssign();
// 	vectorPushPop();
// 	vectorInsert();
// 	vectorErase();
// 	vectorSwap();
// 	vectorClear();
// 	vectorGetAllocator();
// // non-member function overloads
// 	vectorRelationalOperators();
// 	vectorSwapNonMember();
// }

// /*---------------------------------- pair --------------------------------*/

// void	pairConstructor()
// {
// 	std::cout << "<----- PAIR::CONSTRUCTORS ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::pair<std::string, double> p1;
// 	TESTED_NAMESPACE::pair<std::string, double> p2("child1", 1.1);
// 	TESTED_NAMESPACE::pair<std::string, double> p3(p2);

// 	p1 = TESTED_NAMESPACE::make_pair("child0", 0.1);

// 	std::cout << "pair 1: " << p1.first << ", " << p1.second << std::endl;
// 	std::cout << "pair 2: " << p2.first << ", " << p2.second << std::endl;
// 	std::cout << "pair 3: " << p3.first << ", " << p3.second << std::endl;
// }

// void	pairAssignation()
// {
// 	std::cout << "<----- PAIR::OPERATOR=() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::pair<std::string, int> planet, homeplanet;

// 	planet = TESTED_NAMESPACE::make_pair("Earth", 2);

// 	homeplanet = planet;

// 	std::cout << "Homeplanet: " << homeplanet.first << std::endl;
// 	std::cout << "Planet Timeline: " << homeplanet.second << std::endl;	
// }

// void	pairRelationalOperators()
// {	
// 	std::cout << "<----- PAIR::RELATIONAL_OPERATORS() ----->" << std::endl;
// 	std::cout << std::endl;
// 	std::pair<int,char> foo (10,'z');
// 	std::pair<int,char> bar (90,'a');

// 	if (foo == bar) std::cout << "foo and bar are equal\n";
// 	if (foo != bar) std::cout << "foo and bar are not equal\n";
// 	if (foo < bar) std::cout << "foo is less than bar\n";
// 	if (foo > bar) std::cout << "foo is greater than bar\n";
// 	if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
// 	if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";

// }

// void	testPair()
// {
// 	pairConstructor();
// 	pairAssignation();
// 	pairRelationalOperators();
// }

// /*---------------------------------- stack --------------------------------*/

// void	stackConstructors()
// {
// 	std::cout << "<----- STACK::CONSTRUCTORS() ----->" << std::endl;
// 	std::cout << std::endl;
// //	std::deque<int> mydeque(3, 100);					// deque with 3 elements
// 	TESTED_NAMESPACE::vector<int> myvector(2, 200);		// vector with 3 elements

// 	TESTED_NAMESPACE::stack<int> first;					// empty stack
// 	// TESTED_NAMESPACE::stack<int> second(mydeque);		// stack init to copy deque
// 	TESTED_NAMESPACE::stack<int, TESTED_NAMESPACE::vector<int> > third;	// empty stack using vector
// 	TESTED_NAMESPACE::stack<int, TESTED_NAMESPACE::vector<int> > forth(myvector);
	
// 	std::cout << "size of 1st stack: " << first.size() << std::endl;
// 	// std::cout << "size of 2nd stack: " << second.size() << std::endl;
// 	std::cout << "size of 3rd stack: " << third.size() << std::endl;
// 	std::cout << "size of 4th stack: " << forth.size() << std::endl;

// 	std::cout << std::endl;
// }

// // void	stackAssignation()
// // {
// // 	std::cout << "<----- STACK::OPERATOR=() ----->" << std::endl;
// // 	std::cout << std::endl;
// // 	TESTED_NAMESPACE::vector<int> myvector(2, 200);		// vector with 3 elements

// // 	TESTED_NAMESPACE::stack<int> s1;					// empty stack
// // 	TESTED_NAMESPACE::stack<int, TESTED_NAMESPACE::vector<int> > s2(myvector);
	
// // 	s1 = s2;

// // 	std::cout << "stack 1: "; printStack(s1);
// // 	std::cout << "stack 2: "; printStack(s2);
// // 	std::cout << std::endl;
// // }

// void	stackEmpty()
// {
// 	std::cout << "<----- STACK::EMPTY() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::stack<int> s;
// 	int sum (0);

// 	for (int i = 0 ; i < 100 ; i++) s.push(i);

// 	while (!s.empty())
// 	{
// 		sum++;
// 		s.pop();
// 	}
// 	std::cout << "sum is increment until the stack is empty, total sum: " << sum <<  std::endl;

// 	if (s.empty())
// 	{
// 		std::cout << "stack is empty: "; printStack(s);
// 	}
// 	std::cout << std::endl;
// }

// void	stackSize()
// {
// 	std::cout << "<----- STACK::SIZE() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::stack<int> myints;
// 	std::cout << "0. size: " << myints.size() <<  std::endl;

// 	for (int i = 0 ; i < 10 ; i++) myints.push(i);
// 	std::cout << "1. size: " << myints.size() <<  std::endl;
// 	printStack(myints);

// 	myints.pop();
// 	std::cout << "2. size: " << myints.size() <<  std::endl;
// 	printStack(myints);
// 	std::cout << std::endl;
// }

// void	stackTop()
// {
// 	std::cout << "<----- STACK::TOP() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::stack<int> s;
	
// 	s.push(10);
// 	s.push(42);
// 	s.push(66);
// 	std::cout << "the stack: "; printStack(s);
// 	std::cout << "the top stack: " << s.top() << std::endl;
// 	std::cout << std::endl;
// }

// void	stackPushPop()
// {
// 	std::cout << "<----- STACK::PUSH/POP() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::stack<int> s;
	
// 	s.push(10);
// 	s.push(42);
// 	s.push(66);
// 	printStack(s);
	
// 	s.pop();
// 	s.pop();
// 	printStack(s);
	
// 	s.push(101);
// 	s.push(102);
// 	s.push(42);
// 	printStack(s);

// 	s.pop();
// 	s.pop();
// 	printStack(s);
	
// 	std::cout << std::endl;
// }

// void	stackRelationalOperators()
// {
// 	std::cout << "<----- STACK::RELATIONAL_OPERATORS() ----->" << std::endl;
// 	std::cout << std::endl;
// 	TESTED_NAMESPACE::vector<int> v1(3, 100);
// 	TESTED_NAMESPACE::vector<int> v2(2, 200);
// 	TESTED_NAMESPACE::stack<int, TESTED_NAMESPACE::vector<int> > s1(v1);
// 	TESTED_NAMESPACE::stack<int, TESTED_NAMESPACE::vector<int> > s2(v2);

// 	if (s1 == s2) std::cout << "s1 and s2 are equal" << std::endl;
// 	if (s1 != s2) std::cout << "s1 and s2 aren't equal" << std::endl;
// 	if (s1 < s2) std::cout << "s1 is less than s2" << std::endl;
// 	if (s1 > s2) std::cout << "s1 is greater than s2" << std::endl;
// 	if (s1 <= s2) std::cout << "s1 is less than or equal to s2" << std::endl;
// 	if (s1 >= s2) std::cout << "s1 is greater than or equal to s2" << std::endl;

// 	std::cout << std::endl;
// }

// void    testStack()
// {
// 	stackConstructors();
// 	stackEmpty();
// 	stackSize();
// 	stackTop();
// 	stackPushPop();
	
//  // non-member function overloads
//  	stackRelationalOperators();

// 	// stackAssignation();
// }

// void testsTRAITS()
// {
// 	typedef TESTED_NAMESPACE::iterator_traits< TESTED_NAMESPACE::vector< std::string >::iterator > traits;
// 	if (typeid(traits::iterator_category) == typeid(std::random_access_iterator_tag))
// 		std::cout << "standard_iterator is a random-access iterator" << std::endl;
// 	if (typeid(traits::iterator_category) == typeid(std::bidirectional_iterator_tag))
// 		std::cout << "standard_iterator is a bidirectional iterator" << std::endl;

// 	typedef TESTED_NAMESPACE::iterator_traits< std::map< std::string, std::string >::iterator > traits2;
// 	if (typeid(traits2::iterator_category) ==  typeid(std::random_access_iterator_tag))
// 		std::cout << "map_iterator is a random-access iterator" << std::endl;
// 	if (typeid(traits2::iterator_category) == typeid(std::bidirectional_iterator_tag))
// 		std::cout << "map_iterator is a bidirectional iterator" << std::endl;
// }

void testRBT()
{
	std::cout << std::endl;
	ft::RBTree<int, std::vector<int> >	a;
	// ft::RBTree<int, std::vector<int> >	b (a);	// if i want them to work:
	// ft::RBTree<int, std::vector<int> >	b = a;	// need to do an operator= -> deep copy

	a.search_tree(12);

	std::cout << a.get_root() << std::endl;

	std::cout << std::endl;
}

#endif