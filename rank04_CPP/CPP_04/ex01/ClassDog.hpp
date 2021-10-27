/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:12:07 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/27 18:45:46 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLASSDOG_HPP
# define CLASSDOG_HPP

# include "ClassAnimal.hpp"

class Dog: public Animal
{
public:
	Dog();
	Dog( Dog const& cpy);
	virtual ~Dog();

	Dog&	operator=( Dog const& src );

	//member function
	void	makeSound( void ) const;
};

#endif
