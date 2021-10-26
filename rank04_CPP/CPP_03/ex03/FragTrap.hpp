/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:37:32 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/26 19:19:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

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
