/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:22:24 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/26 16:22:25 by louielouie       ###   ########.fr       */
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

	//member functions
//	void	setNameDiamond( std::string name );
	std::string	getNameDiamond() const;
	void	whoAmI();
	void	attack( std::string const& target );

private:
	std::string	_nameDiamond;
};

#endif
