/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:34:48 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/22 20:34:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:
	//default constructor
	Fixed();
	//copy constructor
	Fixed(Fixed const& src);
	//destructor
	~Fixed();
	//assignation operator
	Fixed&	operator=(Fixed const& src);

	int	getRawBits( void ) const;
	void	setRawBits(int const raw);
	
private:
	int	_rawBits;
	static const int	_nbFract = 8;
};

#endif
