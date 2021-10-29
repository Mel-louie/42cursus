/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:45:04 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/29 12:58:00 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include <string>

MateriaSource::MateriaSource( void ): _storage(), _maxStorage(4) {

	std::cout << "MateriaSource default constructor has been called" << std::endl;
	
	for (int i = 0; i < _maxStorage; i++)
		this->_storage[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const& cpy): _storage(), _maxStorage(4) {

	std::cout << "MateriaSource copy constructor has been called" << std::endl;

	for (int i = 0; i < _maxStorage; i++)
		this->_storage[i] = NULL;
	*this = cpy;

	return ;
}

MateriaSource::~MateriaSource(void) {

	std::cout << "MateriaSource destructor has been called" << std::endl;

	for (int i = 0; i < 4; i++)
		if (this->_storage[i] != NULL)
			delete (this->_storage[i]);

	//delete [] this->_storage;
	return ;
}

MateriaSource &MateriaSource::operator=( MateriaSource const &src ) {

	for (int i = 0; i < _maxStorage; i++)
	{
		if (src._storage[i] != NULL)
		{
			if (this->_storage[i] != NULL)
			{
				delete (this->_storage[i]);
				this->_storage[i] = NULL;
			}
			this->_storage[i] = src._storage[i]->clone();
		}
		else
		{
			if (this->_storage[i] != NULL)
			{
				delete (this->_storage[i]);
				this->_storage[i] = NULL;
			}
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m) {

	if ( !m )
		return ;

	int	i = 0;

	while ( i < _maxStorage && this->_storage[i] != NULL )
		i++;

	if ( i < _maxStorage )
		this->_storage[i] = m;
	else
		std::cout << "* can't learn new Materias, storage is full. *" << std::endl;
	return ;
}

AMateria *MateriaSource::createMateria( std::string const& type ) {
	
	AMateria *cpy;

	for (int i = 0; i < _maxStorage; i++)
	{
		if ( this->_storage[i] != NULL && this->_storage[i]->getType() == type )
		{
			cpy = this->_storage[i]->clone();
			return (cpy);
		}
	}
	return (NULL);
}
