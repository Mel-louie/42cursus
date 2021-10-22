/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:34:48 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/22 20:40:04 by user42           ###   ########.fr       */
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
	//int constructor
	Fixed(int const nb);
	//floating point constructor
	Fixed(float const nbf);
	~Fixed();

	Fixed&	operator=(Fixed const& src);

	int	getRawBits( void ) const;
	void	setRawBits(int const raw);

	//fixed point value to floating point value
	float	toFloat(void) const;
	//fixed point value to integer value
	int	toInt(void) const;
	
private:
	int	_rawBits;
	static const int	_nbFract = 8;
};

//operator << overload
std::ostream&	operator<<( std::ostream& os, const Fixed& src );

#endif
