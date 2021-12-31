/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:33:58 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/31 16:01:43 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"
# include <deque>

namespace ft
{
    /*--------------------------------------------------------*/
	/*----------------------- FT::STACK ----------------------*/
	/*
    *   @param T        	Type of container's elements.
	*						Aliased as member type stack::value_type
	*	@param Container	Type of the internal underlying container
	*						object where the elements are stored.
	*						Its value_type shall be T.
	*						Aliased as member type stack::container_type.
	*/

	// template <class T, class Container = std::deque<T> >
	template <class T, class Container = vector<T> >
	class stack
	{
	public:
	
		/*							Aliases						*/
		typedef T			value_type;
		typedef	Container	container_type;
		typedef size_t		size_type;

/*--------------------------------------------------------------*/
/*							Constructors						*/
	/*
	*	default constructor
    *   @param cntr	the type of the underlying container type (defined
	* 				as an alias of the second class template param, Container)
	*/
		explicit stack(const container_type &cntr = container_type()): _container(cntr) {}
	/*
	*	Copy constructor
    *   @param x	object to be copied
	*/
		stack(const stack<T, Container> &x): _container(x._container) {}
		
	/*
	*	Destuctor
	*/
		virtual ~stack() {}

	/*
	*	 Returns whether the stack is empty (i.e. whether its size is 0)
	*/
		bool empty() const	{ return (_container.empty()); };
	/*
	*	Returns the number of elements in the stack
	*/
		size_type size() const	{ return (_container.size()); }
	/*
	*	Returns a reference to the top element in the stack
	*	Since stacks are last-in first-out containers, the
	*	top element is the last element inserted into the stack
	*	This member function effectively calls member back of
	*	the underlying container object
	*/
		value_type	&top() { return (_container.back()); }
		const value_type	&top() const { return (_container.back()); }
	/*
	*	Inserts a new element at the top of the stack
	*/
		void	push(const value_type &val) { _container.push_back(val); }
	/*
	*	Removes a new element at the top of the stack
	*/
		void	pop() { _container.pop_back(); }

/*------------------------------------------------------*/
/*				To access private attributes in			*/
/*				non-member function overloads			*/
		template <class U, class C>
		friend bool operator==(const stack<U, C> &lhs, const stack<U, C> &rhs);
		
		template <class U, class C>
		friend bool operator!=(const stack<U, C> &lhs, const stack<U, C> &rhs);
		
		template <class U, class C>
		friend bool operator<(const stack<U, C> &lhs, const stack<U, C> &rhs);
		
		template <class U, class C>
		friend bool operator<=(const stack<U, C> &lhs, const stack<U, C> &rhs);
		
		template <class U, class C>
		friend bool operator>(const stack<U, C> &lhs, const stack<U, C> &rhs);
		
		template <class U, class C>
		friend bool operator>=(const stack<U, C> &lhs, const stack<U, C> &rhs);

/*--------------------------------------------------------------*/
/*							Attribute							*/
	private:
		container_type	_container;
	};
/*------------------------------------------------------*/
/*				Non-member function overloads			*/
	/*
	*	Relational operators for stack
	*	Performs the appropriate comparison operation between the vector
	*	containers lhs and rhs.
	*	Each of these operator overloads calls the same operator on the underlying container objects
	*/
	template <class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container == rhs._container);
	}
	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container != rhs._container);
	}
	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container < rhs._container);
	}
	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container <= rhs._container);
	}
	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container > rhs._container);
	}
	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container >= rhs._container);
	}
};

#endif