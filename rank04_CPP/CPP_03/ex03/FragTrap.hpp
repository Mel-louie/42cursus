/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:37:32 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/26 14:29:18 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
public:
	FragTrap();
	FragTrap( std::string name );
	FragTrap( FragTrap const& src );
	~FragTrap();
	
	FragTrap&	operator=( FragTrap const& src );

	//member function
	void	highFivesGuys(void);
};

#endif
