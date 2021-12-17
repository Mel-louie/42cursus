#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"
# include <iterator>

namespace ft
{
    template <typename T>
    class randomAcess
	{
	protected:
		T*	_ptr;
	public:
        typedef	std::ptrdiff_t					difference_type;	// ptrdiff_t: Result of pointer subtraction
		typedef	T								value_type;
		typedef T*								pointer;
		typedef	T&								reference;
		typedef	std::random_access_iterator_tag	iterator_category;
        typedef	size_t	                        size_type;

		randomAcess 	() { _ptr = NULL;}
		randomAcess	    (pointer x ) { _ptr = x; }
		randomAcess		(const randomAcess &cpy) { _ptr = cpy.getPtr(); }
		~randomAcess	() {}
		randomAcess	&	operator=(const randomAcess	 &x)
		{
			if (this != x._ptr)
				this = x._ptr;
			return (*this);
		}
		
        reference	operator*() const { return (*_ptr); }
		pointer	    operator->() const { return (_ptr); }
		
        bool operator==(const randomAcess &it) { return (it._ptr == this->_ptr); }
		bool operator!=(const randomAcess &it) { return (it._ptr == this->_ptr); }
		bool operator<=(const randomAcess &it) { return (it._ptr >= this->_ptr); }
		bool operator>=(const randomAcess &it) { return (it._ptr <= this->_ptr); }
		bool operator<(const randomAcess &it) { return (it._ptr > this->_ptr); }
		bool operator>(const randomAcess &it) { return (it._ptr < this->_ptr); }
		
		randomAcess	&	operator++() { _ptr++; return (*this); }									// prefix increment operator: --it
		randomAcess		operator++(int) { randomAcess tmp(this->_ptr); this->_ptr++; return (tmp); }	// postfix increment operator: it--
		randomAcess	&	operator--() { _ptr--; return (*this); }									// prefix decrement operator: --it
		randomAcess		operator--(int) { randomAcess tmp(this->_ptr); this->_ptr--; return (tmp); }	// postfix decrement operator: it--
		
		randomAcess	&	operator+=(const randomAcess &y)
		{
			this->_ptr = this->_ptr + y._ptr;
			return (*this);
		}
		
		randomAcess	&	operator-=(const randomAcess &y)
		{
			this->_ptr = this->_ptr + y._ptr;
			return (*this); 
		}

	/*		            	Getter          			*/
		pointer	    getPtr() const { return (_ptr); }

	/*			Non-members operators overloads			*/
		friend randomAcess		operator+(int nb, const randomAcess	 &x)
		{
			randomAcess	 newIt(x);
			return (newIt += nb);
		}
		
		friend randomAcess		operator-(int nb, const randomAcess	 &x)
		{
			randomAcess	 newIt(x);
			return (newIt -= nb);
		}
	};
}
#endif