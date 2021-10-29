/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:39:58 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/29 12:41:08 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>
# include "AMateria.hpp"

class AMateria;

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void	learnMateria(AMateria*) = 0;
	virtual AMateria*	createMateria(std::string const& type) = 0;
};

#endif
