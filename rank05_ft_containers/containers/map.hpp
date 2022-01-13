/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:54:13 by mel-louie         #+#    #+#             */
/*   Updated: 2022/01/13 18:51:38 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
# define MAP_HPP

# include "../templates/utility.hpp"
# include "../iterators/iterator_traits.hpp"
# include "../iterators/reverse_iterators.hpp"
# include "../iterators/map_iterators.hpp"
# include "rb_tree.hpp"

namespace ft
{
    /*--------------------------------------------------------*/
	/*----------------------- FT::MAP ----------------------*/
	/*
    *   @param T        	
	*	@param T
	*	@param Compare
	*	@param Alloc
	*/

    template < class Key,											// map::key_type
            class T,												// map::mapped_type
            class Compare = std::less<Key>,							// map::key_compare
            class Alloc = std::allocator<ft::pair<const Key, T> >	// map::allocator_type
            >
    class map
	{
	private:
		typedef RBTree<Key, T>							tree_type;

	public:
	
		/*							Aliases						*/
        
        typedef Key										key_type;
        typedef T										mapped_type;
		typedef	ft::pair<const key_type, mapped_type>	value_type;
        typedef Compare									key_compare;
		typedef Alloc									allocator_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;
		typedef size_t									size_type;
		typedef std::ptrdiff_t							difference_type;
	
		typedef map_iterators<pointer, map>				iterator;
		typedef map_iterators<const pointer, map>		const_iterator;

		typedef reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef reverse_iterator<iterator>				reverse_iterator;

		

/*--------------------------------------------------------------*/
/*							Constructors						*/
	/*
	*	default constructor
	*	constructs an empty container, with no elements
    *   @param comp		binary predicate that, taking two element
	* 					keys as argument, returns true if the first
	*					argument goes before the second argument in
	*					the strict weak ordering it defines, and false
	*					otherwise. This shall be a function pointer
	*					or a function object.
	*	@param alloc	allocator object.
	*					The container keeps and uses an internal
	*					copy of this allocator.
	*/
		explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): _alloc(alloc), _key_compare(comp) {}

	/*
	*	range constructor
    *	constructs a container with as many elements as the range
	*	[first,last), with each element constructed from its
	*	corresponding element in that range
	*/
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): _alloc(alloc), _key_compare(comp)
		{
			insert(first, last);
		}

	/*
	*	Copy constructor
    *   @param x	object to be copied
	*/
		
	/*
	*	Destuctor
	*/

	/*
	*	Assignation operator
    *   @param x	object to be copied
	*/

		

/*--------------------------------------------------------------*/
/*						Element access							*/
	
	
/*--------------------------------------------------------------*/
/*							Modifiers							*/
	ft::pair<iterator,bool> insert (const value_type &val)
	{
		return (_tree.insert(val));
	}


	// iterator insert (iterator position, const value_type &val)
	// {
	// 	return 
	// }


	// template <class InputIterator>
	// void insert (InputIterator first, InputIterator last);


/*--------------------------------------------------------------*/
/*							Attribute							*/
	private:
		allocator_type	_alloc;
		key_compare		_key_compare;
		tree_type		_tree;
	};
};

#endif