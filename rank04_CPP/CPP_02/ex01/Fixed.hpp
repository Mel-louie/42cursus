/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:34:48 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/22 17:53:35 by louielouie       ###   ########.fr       */
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
