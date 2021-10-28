/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:12:07 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/28 15:47:36 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLASSDOG_HPP
# define CLASSDOG_HPP

# include "ClassAAnimal.hpp"
# include "ClassBrain.hpp"

class Dog: public AAnimal
{
public:
	Dog();
	Dog( Dog const& cpy);
	virtual ~Dog();

	Dog&	operator=( Dog const& src );

	//setters and getters
	void	setBrain( Brain& brain );
	Brain*	getBrain( void ) const;

	//member function
	void	makeSound( void ) const;

private:
	Brain*	_brain;
};

#endif
