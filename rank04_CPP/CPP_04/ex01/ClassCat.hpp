/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:51:46 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/27 18:57:02 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSCAT_HPP
# define CLASSCAT_HPP

# include "ClassAnimal.hpp"

class Cat: public Animal
{
public:
	Cat();
	Cat( Cat const& cpy);
	virtual ~Cat();
	
	Cat&	operator=( Cat const& src );

	//member function
	void	makeSound( void ) const;	
};

#endif
