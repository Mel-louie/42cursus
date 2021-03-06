/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:30:45 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/27 18:54:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

/*it is the class that can be inherited several times that must be virtual,
 * ClapTrap is inherited by ScavTrap and FragTrap
 *
 *
 *         ClapTrap
 *          /    \
 *         /      \
 *        /        \
 *   ScavTrap     FragTrap
 *        \        /
 *         \      /
 *          \    /
 *        DiamondTrap
*/
class ScavTrap: public virtual ClapTrap
{
public:
	ScavTrap();
	ScavTrap( std::string name);
	ScavTrap( ScavTrap const& src );
	virtual ~ScavTrap();

	ScavTrap&	operator=( ScavTrap const& src );

	//fonction de masquage
	void	attack( std::string const& target );
	void	setDefaultEnergy();
	void	setDefaultHitPoint();
	void	setDefaultAttackDamages();

	//member function
	void	guardGate();
};

#endif
