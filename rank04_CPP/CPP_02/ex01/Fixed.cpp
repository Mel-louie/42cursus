/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:45:33 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/22 17:53:22 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed const& src ): _rawBits(src._rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Fixed::Fixed( int const nb )
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = nb * ( 1 << this->_nbFract);
	return ;
}

Fixed::Fixed( float const nbf )
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(nbf * ( 1 << this->_nbFract));
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed&	Fixed::operator=(Fixed const& src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = src.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	float	ret = static_cast<float>( this->_rawBits )
				/ static_cast<float>( 1 << this->_nbFract );
	return ( ret );
}

int	Fixed::toInt(void) const
{
	return ( this->_rawBits / ( 1 << this->_nbFract ) );
}

std::ostream&	operator<<( std::ostream& os, const Fixed& src )
{
	os << src.toFloat();
	return (os);
}
