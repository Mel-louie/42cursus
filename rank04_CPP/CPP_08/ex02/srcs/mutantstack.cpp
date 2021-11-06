/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:58:20 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/06 16:58:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "../includes/mutantstack.hpp"
#include "../includes/mutantstackTests.hpp"

void	creatMutantStack( void )
{
	std::cout << "<--- Tests on a MutantStack --->" << std::endl;
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);

	std::cout << "On top of the stack: " << mstack.top() << std::endl;
	std::cout << "Stack size: " << mstack.size();
	mstack.pop() ;
	std::cout << " [stack pop] " << "Stack size: " << mstack.size() << std::endl;
	
	//push other numbers on top of the stack
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);
	mstack.push(101);
	mstack.push(0);

	//do some iterator manipulations
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Display stack: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::cout << "Stack size: " << mstack.size() << std::endl;
	
	//copy on a stack container
	std::stack<int> s(mstack);

	//empty stack
	MutantStack<int> empty;
	if ( empty.empty() )
		std::cout << std::endl << "Creation of an empty MutantStack" << std::endl << std::endl;

	//copy mstack in notEmpty
	std::cout << "Create a copy of mstack and display it:" << std::endl;
	MutantStack<int> notEmpty(mstack);
	MutantStack<int>::iterator it2 = notEmpty.begin();
	MutantStack<int>::iterator ite2 = notEmpty.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << " ";
		++it2;
	}
	std::cout << std::endl;
	std::cout << "Modifying and display copy:" << std::endl;
	notEmpty.pop();
	notEmpty.pop();
	notEmpty.pop();
	it2 = notEmpty.begin();
	ite2 = notEmpty.end();
	while (it2 != ite2)
	{
		std::cout << *it2 << " ";
		++it2;
	}

	std::cout << std::endl;
	std::cout << std::endl;
}

void	creatList( void )
{
	std::cout << "<--- Tests on a List --->" << std::endl;
	std::list<int>	lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << "On top of the list: " << lst.back() << std::endl;
	std::cout << "List size: " << lst.size();
	lst.pop_back();
	std::cout << " [list pop] " << "List size: " << lst.size() << std::endl;

	//push other numbers on top of the list
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(42);
	lst.push_back(101);
	lst.push_back(0);
	
	//do some iterator manipulations
	std::list<int>::iterator it2 = lst.begin();
	std::list<int>::iterator ite2 = lst.end();
	++it2;
	--it2;
	std::cout << "Display list: " << std::endl;
	while (it2 != ite2)
	{
		std::cout << *it2 << " ";
		++it2;
	}
	std::cout << std::endl;
	std::cout << "List size: " << lst.size() << std::endl;

	//copy on a stack container	
	std::stack<int, std::list<int> > s2(lst);

	//empty list
	std::list<int> empty;
	if ( empty.empty() )
		std::cout << std::endl << "Creation of an empty List" << std::endl << std::endl;

	//copy lst in notEmpty
	std::cout << "Create a copy of lst and display it:" << std::endl;
	std::list<int> notEmpty(lst);
	std::list<int>::iterator it = notEmpty.begin();
	std::list<int>::iterator ite = notEmpty.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::cout << "Modifying and display copy:" << std::endl;
	notEmpty.pop_back();
	notEmpty.pop_back();
	notEmpty.pop_back();
	it = notEmpty.begin();
	ite = notEmpty.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}

	std::cout << std::endl;
	std::cout << std::endl;
}

void	subjectTest( void )
{
	std::cout << "<--- Subject Test --->" << std::endl;
	
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}
