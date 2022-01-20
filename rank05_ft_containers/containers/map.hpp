/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:54:13 by mel-louie         #+#    #+#             */
/*   Updated: 2022/01/20 18:22:27 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
# define MAP_HPP

# include "../iterators/reverse_map_iterators.hpp"
# include "../iterators/iterator_traits.hpp"
# include "../iterators/map_iterators.hpp"
# include "../containers/utilities.hpp"
# include "../templates/utility.hpp"
# include "rb_tree.hpp"

namespace ft
{
    /*--------------------------------------------------------*/
	/*----------------------- FT::MAP ----------------------*/

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
	class map {
		
		public :
			// member Types 
			typedef Key															key_type;
			typedef T															mapped_type;
			typedef Compare														key_compare;
			typedef Alloc														allocator_type;
			typedef ft::pair<const key_type, mapped_type>						value_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename std::size_t										size_type;
			typedef std::ptrdiff_t												difference_type;
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map;

				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}

				public:
					bool operator()(const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};
		
			typedef ft::bidir_iterator<value_type, ft::node<value_type> >		iterator;
			typedef ft::bidir_iterator<const value_type, ft::node<value_type> >	const_iterator;
			typedef ft::reverse_map_iterators<iterator>							reverse_iterator;
			typedef ft::reverse_map_iterators<const_iterator>					const_reverse_iterator;

		/*----------------------------------------------------------*/
		/*							Constructors					*/
			/*
			*	Empty container constructor = default constructor
			*	Constructs an empty container with no elements
			*/
			explicit map( const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _tree(value_compare(comp) )
			{
				( void )alloc;
			}
			
			/*
			*	range constructor
			*/
			template <class InputIterator>
			map( InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) : _tree(value_compare(comp) )
			{
				( void )alloc;
				insert(first, last);
			}

			/*
			*	Copy Constructor
			*/
			map(const map &copy) : _tree(value_compare(key_compare()))
			{
				insert(copy.begin(), copy.end());
			}
			
			/*
			*	Destructor
			*/
			~map()
			{
				clear();
				_tree.destroy_null();
			}
			/*
			*	Assignation operator
			*	@param x 	the iteration that will be assigned
			*/
			map &operator=(const map &x)
			{
				if (this != &x)
				{
					this->~map();
					_tree = ft::RBTree<value_type, value_compare>(value_compare(key_compare()));
					insert(x.begin(), x.end());
				}
				return (*this);
			}
		/*----------------------------------------------------------*/
		/*						Iterators							*/
			iterator begin() { return (iterator(_tree.get_root(), _tree.min_node(), _tree.get_null())); }
			const_iterator begin() const { return (const_iterator(_tree.get_root(), _tree.min_node(), _tree.get_null())); }
			iterator end() { return (iterator(_tree.get_root(), _tree.get_null(), _tree.get_null())); }
			const_iterator end() const { return (const_iterator(_tree.get_root(), _tree.get_null(), _tree.get_null())); }
			reverse_iterator rbegin() { return (reverse_iterator(end())); }
			const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); }
			reverse_iterator rend() { return (reverse_iterator(begin())); }
			const_reverse_iterator rend() const { return (const_reverse_iterator(begin())); }

		/*----------------------------------------------------------*/
		/*						Capacity							*/
			bool empty() const { return (!_tree.get_size()); }
			size_type size() const { return (_tree.get_size()); }
			size_type max_size() const { return (_tree.max_size()); }

		/*----------------------------------------------------------*/
		/*					Element access							*/
			mapped_type &operator[]( const key_type & k ) { return (insert(ft::make_pair(k, mapped_type())).first->second); }


		/*----------------------------------------------------------*/
		/*						Modifiers							*/
			ft::pair<iterator, bool> insert( const value_type &val )
			{
				if (_tree.insert(val) == false)
					return (ft::make_pair(find(val.first), false));
				return (ft::make_pair(find(val.first), true));
			}

			iterator insert( iterator position, const value_type &val )
			{
				( void )position;
				return (insert(val).first);
			}

			template <class InputIterator>
			void insert( InputIterator first, InputIterator last )
			{
				while (first != last)
				{
					insert(*first++);
				}
			}
			
			/*
			*	erase():
			*		removes from the map container either a single element or a range
			*		of elements.
			*		1) by position
			*		2) by key
			*		3) by iterator == range
			*/
			void erase( iterator position )
			{
				erase(position->first);
			}

			size_type erase( const key_type &k )
			{
				if (_tree.delete_node(ft::make_pair(k, mapped_type())) == false)
					return (0);
				return (1);
			}

			void erase( iterator first, iterator last )
			{
				while (first != last)
				{
					first = find(first->first);
					erase(first++);
				}
			}

			void swap( map &x ) { _tree.swap(x._tree); }

			void clear() { _tree.destroy(); }


		/*----------------------------------------------------------*/
		/*						Observers							*/
		/*Returns a copy of the comparison object used by the container to compare keys.
		* The comparison object of a map object is set on construction. Its type (member key_compare)
		* is the third template parameter of the map template. By default, this is a less object,
		* which returns the same as operator<.
		*/
			key_compare key_comp() const { return (key_compare()); }

		/*The comparison object returned is an object of the member type map::value_compare,
		* which is a nested class that uses the internal comparison object to generate the
		* appropriate comparison functional class. It is defined with the same behavior as:
		*/
			value_compare value_comp() const { return (value_compare(key_comp())); }
			
		/*----------------------------------------------------------*/
		/*						Operations							*/
			iterator find( const key_type &k )
			{
				return (iterator(_tree.get_root(), _tree.search(ft::make_pair(k, mapped_type())), _tree.get_null()));
			}

			const_iterator find(const key_type & k) const
			{
				return (iterator(_tree.get_root(), _tree.search(ft::make_pair(k, mapped_type())), _tree.get_null()));
			}

			size_type count( const key_type &k ) const
			{
				if (find(k) == end())
					return (0);
				return (1);
			}

			iterator lower_bound( const key_type &k )
			{
				return (iterator(_tree.get_root(), _tree.lower_bound(ft::make_pair(k, mapped_type())), _tree.get_null()));
			}
	
			const_iterator lower_bound( const key_type &k ) const
			{
				return (const_iterator(_tree.get_root(), _tree.lower_bound(ft::make_pair(k, mapped_type())), _tree.get_null()));
			}

			iterator upper_bound( const key_type & k )
			{
				return (iterator(_tree.get_root(), _tree.upper_bound(ft::make_pair(k, mapped_type())), _tree.get_null()));
			}

			const_iterator upper_bound( const key_type & k ) const
			{
				return (const_iterator(_tree.get_root(), _tree.upper_bound(ft::make_pair(k, mapped_type())), _tree.get_null()));
			}

			ft::pair<const_iterator, const_iterator> equal_range( const key_type &k ) const
			{
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
			}

			ft::pair<iterator, iterator> equal_range( const key_type &k )
			{
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
			}

		/*----------------------------------------------------------*/
		/*						Allocator							*/
			allocator_type get_allocator() const
			{
				return (allocator_type());
			}

			void	print()
			{
				_tree.printRBT();
			}

		private :
			ft::RBTree<value_type, value_compare>			_tree;
	};

	/*
	*	non-member function overloads
	*	Performs the appropriate comparaison operation between lhs and rhs.
	*	Each of these operator overloads calls the same operator on the underlying
	*	container objects.
	*/
	template <class Key, class T, class Compare, class Allocator>
	bool operator==( const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs )
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator!=( const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs )
	{
		if (lhs.size() != rhs.size())
			return (true);
		return (!ft::equal(lhs.begin(), lhs.end(), rhs.begin())); 
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator<( const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator<=( const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs )
	{
		return (!(rhs < lhs));
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator>( const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs )
	{
		return (!(rhs >= lhs));
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator>=( const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs )
	{
		return (!ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Allocator>
	void swap( map<Key, T, Compare, Allocator> &x, map<Key, T, Compare, Allocator> &y )
	{
		return (x.swap(y));
	}
};

#endif