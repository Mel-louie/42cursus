/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:31:21 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/22 19:05:55 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << "a\t= " << a << std::endl;
	std::cout << "++a\t= " << ++a << std::endl;
	std::cout << "a\t= " << a << std::endl;
	std::cout << "a++\t= "<< a++ << std::endl;
	std::cout << "a\t= " << a << std::endl;
	std::cout << "--a\t= " << --a << std::endl;
	std::cout << "a\t= " << a << std::endl;
	std::cout << std::endl;

	std::cout << "b\t= " << b << std::endl;
	std::cout << std::endl;
	
	std::cout << "a < b ?\t= " << a.operator<(b) << std::endl;
	std::cout << std::endl;

	std::cout << "b / a\t= " << b.operator/(a) << std::endl;
	std::cout << std::endl;

	std::cout << "max(" << a << ", " << b << ")\t = " << Fixed::max(a, b) << std::endl;
	std::cout << "min(" << a << ", " << b << ")\t = " << Fixed::min(a, b) << std::endl;
	std::cout << std::endl;

	return 0;
}
