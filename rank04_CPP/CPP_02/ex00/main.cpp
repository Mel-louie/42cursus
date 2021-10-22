/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:31:21 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/22 20:37:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {

	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	// std::cout << std::endl << std::endl;
	// std::cout << "One other test:" << std::endl;
	// Fixed	d;
	// d.setRawBits(42);
	// std::cout << d.getRawBits() << std::endl;

	std::cout << std::endl << std::endl;
	return 0;
}
