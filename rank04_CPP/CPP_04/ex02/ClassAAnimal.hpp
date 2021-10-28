/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassAAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:28:59 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/28 15:44:12 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <string>
# include <iostream>

class AAnimal
{
public:
	//canonical class
	AAnimal();
	AAnimal( AAnimal const& cpy );
	virtual ~AAnimal();

	AAnimal&	operator=( AAnimal const& src );
	//

	//setter and getter
	void	setType( std::string const& type );
	std::string	getType( void ) const ;

	//member function
	virtual void	makeSound( void ) const = 0;

protected:
	std::string	_type;
};

#endif