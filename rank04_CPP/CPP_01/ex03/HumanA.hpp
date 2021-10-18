/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:02:16 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/18 14:42:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
public:
	HumanA( Weapon& weapon );
	HumanA( const std::string& name, Weapon& weapon );
	~HumanA();

	void	setWeapon( const Weapon& weapon);
	void	setName( const std::string name);

	const Weapon&	getWeapon( void ) const;
	std::string	getName( void ) const;

	void	attack( void );
	
private:
	std::string	_name;
	Weapon&	_weapon;
};

#endif
