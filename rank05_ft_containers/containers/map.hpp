/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:54:13 by mel-louie         #+#    #+#             */
/*   Updated: 2022/01/07 16:56:07 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
# define MAP_HPP

# include "../templates/utility.hpp"
# include "../iterators/iterator_traits.hpp"
# include "../iterators/reverse_iterators.hpp"
# include "../iterators/map_iterators.hpp"

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

    template < class Key,                               // map::key_type
            class T,                                     // map::mapped_type
            class Compare = std::less<Key>,                   // map::key_compare
            class Alloc = std::allocator<pair<const Key,T> >  // map::allocator_type
            >
    class map
	{
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
    *   @param
	*/

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
/*							Attribute							*/
	private:
		allocator_type	_alloc;;
	};
};

#endif