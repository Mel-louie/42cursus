/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:22:24 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/27 19:00:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>

class DiamondTrap: public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap( std::string name );
	DiamondTrap( DiamondTrap const& src );
	virtual ~DiamondTrap();

	DiamondTrap&	operator=( DiamondTrap const& src );

	//setters and getters
	std::string	getNameDiamond() const;
	unsigned int	getHitPointsDiamond( void );
	unsigned int	getEnergyPointsDiamond( void );
	unsigned int	getAttackDamageDiamond( void );
	void	setHitPointsDiamond( void );
	void	setEnergyPointsDiamond(void );
	void	setAttackDamageDiamond( void );


	//member functions
	void	whoAmI();
	void	attack( std::string const& target );

private:
	std::string	_nameDiamond;
};

#endif
