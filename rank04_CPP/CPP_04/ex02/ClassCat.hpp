/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:51:46 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/28 15:47:36 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSCAT_HPP
# define CLASSCAT_HPP

# include "ClassAAnimal.hpp"
# include "ClassBrain.hpp"

class Cat: public AAnimal
{
public:
	Cat();
	Cat( Cat const& cpy);
	virtual ~Cat();
	
	Cat&	operator=( Cat const& src );

	//setters and getters
	void	setBrain( Brain& brain );
	Brain*	getBrain( void ) const;

	//member function
	void	makeSound( void ) const;

private:
	Brain*	_brain;
};

#endif
