/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:14:08 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/29 11:15:01 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Cure: public AMateria
{
public:
	Cure( void );
	Cure( Cure const& cpy );
	Cure( std::string const& type );
	
	virtual ~Cure( void );

	Cure&	operator=( Cure const& src );

	AMateria*	clone( void ) const;
	void	use( ICharacter& target );
};

#endif
