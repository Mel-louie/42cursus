/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassWrongWrongCat.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:51:46 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/27 19:31:40 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSWrongCat_HPP
# define CLASSWrongCat_HPP

# include "ClassWrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:
	WrongCat();
	WrongCat( WrongCat const& cpy);
	virtual ~WrongCat();
	
	WrongCat&	operator=( WrongCat const& src );

	//member function
	void	makeSound( void ) const;	
};

#endif
