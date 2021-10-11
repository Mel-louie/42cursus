/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:35:54 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/11 10:41:51 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
public:

	Zombie( void );
	~Zombie( void );

	//member function
	void	announce( void );

private:
		std::string	_name;
};

Zombie* newZombie( std::string name );

void randomChump( std::string name );

#endif
