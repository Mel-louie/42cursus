/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:22:24 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/26 15:27:57 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <string>

class DiamondTrap: public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap( std::string name );
	DiamondTrap( DiamondTrap const& src );
	~DiamondTrap();

	DiamondTrap&	operator=( DiamondTrap const& src );

	//member functions
	std::string	getNameDiamond();
	void	whoAmI();

private:
	std::string	_nameDiamond;
};

#endif
