/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:06:16 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/29 15:50:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string	_type;

public:
	AMateria( void );
	AMateria( AMateria const& cpy );
	AMateria( std::string const& type );

	virtual ~AMateria( void );
	
	AMateria&	operator=( AMateria const& src );
	
	//getter
	std::string const&	getType( void ) const; //Returns the materia type

	//member functions
	virtual AMateria*	clone( void ) const = 0;
	virtual void	use( ICharacter& target );
};

#endif
