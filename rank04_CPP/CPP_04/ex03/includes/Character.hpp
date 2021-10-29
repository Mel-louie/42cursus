/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:50:13 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/29 13:02:17 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
private:
	int	_matMax;
	std::string	_name;
	AMateria*	_inventory[4];

public:
	Character( void );
	Character( Character const& cpy );
	Character( std::string const& name );
	
	virtual ~Character( void );

	Character&	operator=( Character const& src);
	
	//getter
	std::string const&	getName( void ) const;

	//member functions
	void	equip(AMateria* m);
	void	unequip(int idx);
	void 	use(int idx, ICharacter& target);
};

#endif
