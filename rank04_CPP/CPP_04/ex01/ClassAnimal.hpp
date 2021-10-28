/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:28:59 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/28 15:44:12 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
public:
	//canonical class
	Animal();
	Animal( Animal const& cpy );
	virtual ~Animal();

	Animal&	operator=( Animal const& src );
	//

	//setter and getter
	void	setType( std::string const& type );
	std::string	getType( void ) const ;

	//member function
	virtual void	makeSound( void ) const;

protected:
	std::string	_type;
};

#endif