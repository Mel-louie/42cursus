/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:51:34 by user42            #+#    #+#             */
/*   Updated: 2021/10/15 15:15:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
public:
	Zombie(std::string name);
	~Zombie();
	void	announce( void );
	std::string	getName( void );
	
private:
	std::string	_name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif