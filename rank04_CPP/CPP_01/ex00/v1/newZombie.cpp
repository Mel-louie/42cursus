/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:49:10 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/11 13:41:56 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//create a new Zombie, with dynamic allocation (new)
Zombie* newZombie( std::string name )
{
	Zombie	*nwZmbie = new Zombie(name);
	
	return (nwZmbie);
}