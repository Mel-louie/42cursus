/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:34:48 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/22 18:16:31 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const& src);
	Fixed(int const nb);
	Fixed(float const nbf);
	~Fixed();

	Fixed&	operator=(Fixed const& src);

	//comparaison operators
	bool operator==(Fixed const& cmp) const;
	bool operator!=(Fixed const& cmp) const;
	bool operator>(Fixed const& cmp) const;
	bool operator<(Fixed const& cmp) const;
	bool operator>=(Fixed const& cmp) const;
	bool operator<=(Fixed const& cmp) const;

	//arithmetic operators
	Fixed	operator+(Fixed const& add) const ;
	Fixed	operator-(Fixed const& sub) const ;
	Fixed	operator*(Fixed const& mul) const ;
	Fixed	operator/(Fixed const& div) const ;

	//increment operators
	Fixed&	operator++( void );
	Fixed	operator++( int );

	//decrement operators
	Fixed&	operator--( void );
	Fixed	operator--( int );

	//min
	static Fixed&		min( Fixed& a, Fixed& b );
	static const Fixed&	min( Fixed const& a, Fixed const& b );
	//max
	static Fixed&		max( Fixed& a, Fixed& b );
	static const Fixed&	max( Fixed const& a, Fixed const& b );

	int	getRawBits( void ) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int	toInt(void) const;
	
private:
	int	_rawBits;
	static const int	_nbFract = 8;
};

std::ostream&	operator<<( std::ostream& os, const Fixed& src );

#endif
