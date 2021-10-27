/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:37:32 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/27 12:55:34 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

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
class FragTrap: public virtual ClapTrap
{
public:
	FragTrap();
	FragTrap( std::string name );
	FragTrap( FragTrap const& src );
	virtual ~FragTrap();
	
	FragTrap&	operator=( FragTrap const& src );

	//fonction de masquage
	void	attack( std::string const& target );

	//member function
	void	highFivesGuys(void);
};

#endif
