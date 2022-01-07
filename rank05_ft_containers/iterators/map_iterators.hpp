#ifndef MAP_ITERATORS_HPP
# define MAP_ITERATORS_HPP

# include "./iterator_traits.hpp"
# include "./iterators.hpp"
# include "../templates/type_traits.hpp"

namespace ft
{
		template<typename Iterator, typename Container>
		class map_iterators
		{
		protected:
			Iterator							_it;
			typedef iterator_traits<Iterator>	traits;
		public:
			typedef Iterator							iterator_type;
			typedef typename traits::iterator_category	iterator_category;
			typedef typename traits::value_type			value_type;
			typedef typename traits::difference_type	difference_type;
			typedef typename traits::reference			reference;
			typedef typename traits::pointer			pointer;

			map_iterators() {}
		};
    
} // namespace ft


#endif
