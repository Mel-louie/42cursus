/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:58:50 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/26 16:22:06 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
public:
//canonical class
	ClapTrap();
	ClapTrap( std::string name);
	ClapTrap( ClapTrap const& src );
	virtual ~ClapTrap();

	ClapTrap&	operator=( ClapTrap const& src );
//

	//getters
	std::string	getName( void ) const;
	unsigned int	getHitPoints( void ) const;
	unsigned int	getEnergyPoints( void ) const;
	unsigned int	getAttackDamage( void ) const;

	//setters
	void	setName( std::string name);
	void	setHitPoints( unsigned int hitPoints );
	void	setEnergyPoints( unsigned int energyPoints );
	void	setAttackDamage( unsigned int attackDamage );

	//member functions
	void	attack( std::string const& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

protected:
	std::string	_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
};

#endif
