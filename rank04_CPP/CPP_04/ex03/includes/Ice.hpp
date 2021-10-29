/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 09:48:36 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/29 11:05:01 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Ice: public AMateria
{
public:
	Ice( void );
	Ice( Ice const& cpy );
	Ice( std::string const& type );
	
	virtual ~Ice( void );

	Ice&	operator=( Ice const& src );

	AMateria*	clone( void ) const;
	void	use( ICharacter& target );
};

#endif