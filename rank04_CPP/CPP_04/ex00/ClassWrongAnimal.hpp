/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassWrongWrongAnimal.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:28:59 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/27 19:22:03 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

# include <string>
# include <iostream>

/*
 * in this class, makeSound() isn't a virtual function
 * so dynamics links aren't possibles, and WrongCat does
 * a wrong sound
 */

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal( WrongAnimal const& cpy );
	virtual ~WrongAnimal();

	WrongAnimal&	operator=( WrongAnimal const& src );

	//setter and getter
	void	setType( std::string const& type );
	std::string	getType( void ) const ;

	//member function
	void	makeSound( void ) const;

protected:
	std::string	_type;
};

#endif