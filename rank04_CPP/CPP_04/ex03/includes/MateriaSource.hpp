/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:39:58 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/29 12:50:27 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include "IMateriaSource.hpp"
# include <string>

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource( void );
	MateriaSource( MateriaSource const &cpy );
	virtual ~MateriaSource( void );

	MateriaSource&	operator=( MateriaSource const &src );
	virtual void	learnMateria( AMateria *m );
	virtual AMateria*	createMateria( std::string const &type );

private:
	AMateria*	_storage[4];
	int	_maxStorage;
};

#endif
