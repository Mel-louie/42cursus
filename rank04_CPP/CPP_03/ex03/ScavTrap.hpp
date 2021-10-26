/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:30:45 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/26 16:41:31 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

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

	//member function
	void	guardGate();
};

#endif
