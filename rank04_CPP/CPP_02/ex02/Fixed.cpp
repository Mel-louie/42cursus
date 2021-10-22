/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:45:33 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/22 18:54:55 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0)
{
	return ;
}

Fixed::Fixed( Fixed const& src ): _rawBits(src._rawBits)
{
	return ;
}

Fixed::Fixed( int const nb )
{
	this->_rawBits = nb * ( 1 << this->_nbFract);
	return ;
}

Fixed::Fixed( float const nbf )
{
	this->_rawBits = roundf(nbf * ( 1 << this->_nbFract));
	return ;
}

Fixed::~Fixed()
{
	return ;
}

Fixed&	Fixed::operator=(Fixed const& src)
{
	this->_rawBits = src.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw)
{
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

//comparaison operators

bool	Fixed::operator==( Fixed const& cmp ) const
{
	return ( toFloat() == cmp.toFloat() );
}

bool	Fixed::operator!=( Fixed const& cmp ) const
{
	return !( *this == cmp );
}

bool	Fixed::operator<( Fixed const& cmp ) const
{
	return ( toFloat() < cmp.toFloat() );
}

bool	Fixed::operator>( Fixed const& cmp ) const
{
	return ( toFloat() > cmp.toFloat() );
}

bool	Fixed::operator<=( Fixed const& cmp ) const
{
	return ( toFloat() <= cmp.toFloat() );
}

bool	Fixed::operator>=( Fixed const& cmp ) const
{
	return ( toFloat() >= cmp.toFloat() );
}

//arithmetic operators
Fixed	Fixed::operator+( Fixed const& add ) const
{
	return ( Fixed( toFloat() + add.toFloat() ) );
}

Fixed	Fixed::operator-( Fixed const& sub ) const
{
	return ( Fixed( toFloat() - sub.toFloat() ) );
}

Fixed	Fixed::operator*( Fixed const& mul ) const
{
	return ( Fixed( toFloat() * mul.toFloat() ) );
}

Fixed	Fixed::operator/( Fixed const& div ) const
{
	return ( Fixed( toFloat() / div.toFloat() ) );
}

//increment operators
Fixed&	Fixed::operator++( void )
{
	++_rawBits;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	old(*this);

	operator++();
	return (old);
}

//decrement operators
Fixed&	Fixed::operator--( void )
{
	--_rawBits;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	old(*this);

	operator--();
	return (old);
}

//returns a reference to the smallest value
Fixed&	Fixed::min( Fixed& a, Fixed& b )
{
	if (a < b)
		return (a);
	return (b);
}

//returns a reference to the smallest const value
const Fixed&	Fixed::min( const Fixed& a, const Fixed& b )
{
	if (a < b)
		return (a);
	return (b);
}

//returns a reference to the max value
Fixed&	Fixed::max( Fixed& a, Fixed& b )
{
	if (a > b)
		return (a);
	return (b);
}

//returns a reference to the max const value
const Fixed&	Fixed::max( const Fixed& a, const Fixed& b )
{
	if (a > b)
		return (a);
	return (b);
}

