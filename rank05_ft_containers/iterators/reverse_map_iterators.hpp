
#ifndef reverse_map_iterators_HPP
# define reverse_map_iterators_HPP

# include <iostream>

# include <iostream>
# include "../iterators/iterator_traits.hpp"
# include "../containers/utilities.hpp"

namespace ft
{
	template <class Iter>
	class reverse_map_iterators
	{
		public:
			
			typedef Iter													iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer				pointer;
			typedef typename ft::iterator_traits<Iter>::reference			reference;
		
			reverse_map_iterators( void ) : _element() {}

			explicit reverse_map_iterators( iterator_type it ) : _element(it) {}

			template< class Iter2 >
			reverse_map_iterators( const reverse_map_iterators<Iter2> &other ) : _element(other.base()) {}

			reverse_map_iterators &operator=( const reverse_map_iterators &other )
			{
				if (this != &other)
					this->_element = other.base();
				return (*this);
			}

			virtual ~reverse_map_iterators( void ) {}

			reference operator*( void ) const
			{
				iterator_type tmp = this->_element;
				return (*(--tmp));
			}

			pointer operator->( void ) const { return &(this->operator*()); }

			reverse_map_iterators &operator++()
			{
				--_element;
				return (*this);
			}

			reverse_map_iterators operator++(int)
			{
				reverse_map_iterators tmp(*this);
				operator++();
				return (tmp);
			}

			reverse_map_iterators &operator--( void )
			{
				++_element;
				return (*this);
			}

			reverse_map_iterators operator--( int )
			{
				reverse_map_iterators tmp(*this);
				operator--();
				return (tmp);
			}

			reverse_map_iterators operator+( difference_type n ) const
			{
				return (reverse_map_iterators(this->_element - n));
			}

			reverse_map_iterators operator-( difference_type n ) const
			{
				return (reverse_map_iterators(this->_element + n));
			}

			reverse_map_iterators &operator+=( difference_type n)
			{
				_element -= n;
				return (*this);
			}

			reverse_map_iterators &operator-=( difference_type n )
			{
				this->_element += n;
				return (*this);
			}

			reference operator[]( difference_type n ) const
			{
				return (this->_element[-n - 1]);
			}

			iterator_type base( void ) const
			{
				return (this->_element);
			}

		private:
			iterator_type				_element;
	};

	template<class Iter>
	bool operator==( const ft::reverse_map_iterators<Iter> &lhs, const ft::reverse_map_iterators<Iter> &rhs )
	{
		return (lhs.base() == rhs.base());
	}

	template<class Iter1, class Iter2>
	bool operator==( const ft::reverse_map_iterators<Iter1> &lhs, const ft::reverse_map_iterators<Iter2> &rhs )
	{
		return (lhs.base() == rhs.base());
	}

	template<class Iter>
	bool operator!=( const ft::reverse_map_iterators<Iter> &lhs, const ft::reverse_map_iterators<Iter> &rhs )
	{
		return (lhs.base() != rhs.base());
	}

	template<class Iter1, class Iter2>
	bool operator!=( const ft::reverse_map_iterators<Iter1> &lhs, const ft::reverse_map_iterators<Iter2> &rhs )
	{
		return (lhs.base() != rhs.base());
	}

	template<class Iter>
	bool operator<( const ft::reverse_map_iterators<Iter> &lhs, const ft::reverse_map_iterators<Iter> &rhs )
	{
		return (lhs.base() > rhs.base());
	}

	template<class Iter1, class Iter2>
	bool operator<( const ft::reverse_map_iterators<Iter1> &lhs, const ft::reverse_map_iterators<Iter2> &rhs )
	{
		return (lhs.base() > rhs.base());
	}

	template<class Iter>
	bool operator>( const ft::reverse_map_iterators<Iter> &lhs, const ft::reverse_map_iterators<Iter> &rhs )
	{
		return (lhs.base() < rhs.base());
	}

	template<class Iter1, class Iter2>
	bool operator>( const ft::reverse_map_iterators<Iter1> &lhs, const ft::reverse_map_iterators<Iter2> &rhs )
	{
		return (lhs.base() < rhs.base());
	}

	template<class Iter>
	bool operator<=( const ft::reverse_map_iterators<Iter> &lhs, const ft::reverse_map_iterators<Iter> &rhs )
	{
		return (lhs.base() >= rhs.base());
	}

	template<class Iter1, class Iter2>
	bool operator<=( const ft::reverse_map_iterators<Iter1> &lhs, const ft::reverse_map_iterators<Iter2> &rhs )
	{
		return (lhs.base() >= rhs.base());
	}

	template<class Iter>
	bool operator>=( const ft::reverse_map_iterators<Iter> &lhs, const ft::reverse_map_iterators<Iter> &rhs )
	{
		return (lhs.base() <= rhs.base());
	}

	template<class Iter1, class Iter2>
	bool operator>=( const ft::reverse_map_iterators<Iter1> &lhs, const ft::reverse_map_iterators<Iter2> &rhs )
	{
		return (lhs.base() <= rhs.base());
	}

	template<class Iter>
	typename ft::reverse_map_iterators<Iter>::difference_type
	operator-( const ft::reverse_map_iterators<Iter> &lhs, const ft::reverse_map_iterators<Iter> &rhs )
	{
		return (rhs.base() - lhs.base());
	}

	template<class Iter1, class Iter2>
	typename ft::reverse_map_iterators<Iter1>::difference_type
	operator-( const ft::reverse_map_iterators<Iter1> &lhs, const ft::reverse_map_iterators<Iter2> &rhs )
	{
		return (rhs.base() - lhs.base());
	}

	template<class Iter>
	ft::reverse_map_iterators<Iter> operator+( 
		typename ft::reverse_map_iterators<Iter>::difference_type n, typename ft::reverse_map_iterators<Iter> &it)
	{
		return ((it + n));
	}
}

#endif