/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:26:01 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/29 15:56:02 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STANDARD_ITERATOR_HPP
# define STANDARD_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "../templates/type_traits.hpp"

	/*--------------------------------------------------------------------*/
	/*---------------------- FT::STANDARD_ITERATORS ----------------------*/

namespace ft
{

	template <typename Iterator, typename Container>
	class standard_iterator
	{
	protected:
		Iterator _it;
		typedef iterator_traits< Iterator > traits;

	public:
		typedef Iterator							iterator_type;
		typedef typename traits::iterator_category	iterator_category;
		typedef typename traits::value_type			value_type;
		typedef typename traits::difference_type	difference_type;
		typedef typename traits::reference			reference;
		typedef typename traits::pointer			pointer;

		standard_iterator() : _it(Iterator()) {}
		explicit standard_iterator(const Iterator &it) : _it(it) {}
		template < typename T >
		standard_iterator(const standard_iterator<T, typename enable_if< is_same< T,
							typename Container::pointer >::value, Container >::type > &it): _it(it.base()) {}

		/*---------------------- forward ----------------------*/
		reference operator*() const { return *_it; }
		pointer operator->() const { return _it; }
		standard_iterator &operator++() { ++_it; return (*this); }
		standard_iterator operator++(int) { return (standard_iterator(_it++)); }

		/*---------------------- bidirectionnal ----------------------*/
		standard_iterator &operator--() { --_it; return (*this); }
		standard_iterator operator--(int) { return standard_iterator(_it--); }

		/*---------------------- random access ----------------------*/
		reference operator[](difference_type ptr) const { return _it[ptr]; }
		standard_iterator &operator+=(difference_type ptr) { _it += ptr; return (*this); }
		standard_iterator operator+(difference_type ptr) const { return (standard_iterator(_it + ptr)); }
		standard_iterator &operator-=(difference_type ptr) { _it -= ptr; return (*this); }
		standard_iterator operator-(difference_type ptr) const { return standard_iterator(_it - ptr); }
		const Iterator &base() const { return _it; }
	};

	// non-member
	template < typename IteratorL, typename IteratorR, typename Container >
	inline bool operator==(const standard_iterator< IteratorL, Container > &lhs,
                       const standard_iterator< IteratorR, Container > &rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template < typename Iterator, typename Container >
	bool operator==(const standard_iterator< Iterator, Container > &lhs,
				const standard_iterator< Iterator, Container > &rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template < typename IteratorL, typename IteratorR, typename Container >
	bool operator!=(const standard_iterator< IteratorL, Container > &lhs,
					const standard_iterator< IteratorR, Container > &rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template < typename Iterator, typename Container >
	bool operator!=(const standard_iterator< Iterator, Container > &lhs,
				const standard_iterator< Iterator, Container > &rhs) 
	{
		return (lhs.base() != rhs.base());
	}
	template < typename IteratorL, typename IteratorR, typename Container >
	bool operator<(const standard_iterator< IteratorL, Container > &lhs,
				const standard_iterator< IteratorR, Container > &rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template < typename Iterator, typename Container >
	bool operator<(const standard_iterator< Iterator, Container > &lhs,
				const standard_iterator< Iterator, Container > &rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template < typename IteratorL, typename IteratorR, typename Container >
	bool operator>(const standard_iterator< IteratorL, Container > &lhs,
				const standard_iterator< IteratorR, Container > &rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template < typename Iterator, typename Container >
	bool operator>(const standard_iterator< Iterator, Container > &lhs,
				const standard_iterator< Iterator, Container > &rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template < typename IteratorL, typename IteratorR, typename Container >
	bool operator<=(const standard_iterator< IteratorL, Container > &lhs,
					const standard_iterator< IteratorR, Container > &rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template < typename Iterator, typename Container >
	bool operator<=(const standard_iterator< Iterator, Container > &lhs,
					const standard_iterator< Iterator, Container > &rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template < typename IteratorL, typename IteratorR, typename Container >
	bool operator>=(const standard_iterator< IteratorL, Container > &lhs,
					const standard_iterator< IteratorR, Container > &rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template < typename Iterator, typename Container >
	bool operator>=(const standard_iterator< Iterator, Container > &lhs,
					const standard_iterator< Iterator, Container > &rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template < typename IteratorL, typename IteratorR, typename Container >
	typename standard_iterator< IteratorL, Container >::difference_type
		operator-(const standard_iterator< IteratorL, Container > &lhs,
			const standard_iterator< IteratorR, Container > &rhs)
	{
		return (lhs.base() - rhs.base());
	}
}

#endif
