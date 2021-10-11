/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:00:51 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/11 14:30:07 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
public:

	//constructors and destructor
	Zombie( void );
	Zombie(std::string name);
	~Zombie( void );

	//setter + getter
	void	setName(std::string);
	std::string	getName(void);

	//member function
	void	announce( void );

private:
		std::string	_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
