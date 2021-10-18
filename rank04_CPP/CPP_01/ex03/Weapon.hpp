/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:02:16 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/18 13:58:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
public:
	Weapon();
	Weapon(const std::string& type );
	~Weapon();

	void	setType( const std::string& type );
	const std::string&	getType( void ) const;

private:
	std::string	_type;
};

#endif
