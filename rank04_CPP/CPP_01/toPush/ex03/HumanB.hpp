/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:02:16 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/18 14:44:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
public:
	HumanB( void );
	HumanB( const std::string& name);
	~HumanB();

	void	setWeapon( Weapon& weapon);
	void	setName( const std::string name);

	const Weapon*	getWeapon( void ) const;
	std::string	getName( void ) const;

	void	attack( void );
	
private:
	std::string	_name;
	Weapon*	_weapon;
};

#endif
