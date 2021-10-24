/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:31:21 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/24 18:43:08 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

//increment decrement
	std::cout << "a\t= " << a << std::endl;
	std::cout << "++a\t= " << ++a << std::endl;
	std::cout << "a\t= " << a << std::endl;
	std::cout << "a++\t= "<< a++ << std::endl;
	std::cout << "a\t= " << a << std::endl;
	std::cout << "--a\t= " << --a << std::endl;
	std::cout << "a\t= " << a << std::endl;
	std::cout << "a--\t= " << a-- << std::endl;
	std::cout << "a\t= " << a << std::endl;
	std::cout << "++a\t= " << ++a << std::endl;
	std::cout << "a\t= " << a << std::endl;
	std::cout << std::endl;

	std::cout << "b\t= " << b << std::endl;
	std::cout << std::endl;

//comparaison operators
	std::cout << "a < b ?\t\t= " << a.operator<(b) << std::endl;
	std::cout << "a > b ?\t\t= " << a.operator>(b) << std::endl;
	std::cout << "a == b ?\t= " << a.operator==(b) << std::endl;
	std::cout << "a != b ?\t= " << a.operator!=(b) << std::endl;
	std::cout << "a >= b ?\t= " << a.operator>=(b) << std::endl;
	std::cout << "a <= b ?\t= " << a.operator<=(b) << std::endl;
	std::cout << std::endl;

//arithmetic operators
	std::cout << "b / a\t= " << b.operator/(a) << std::endl;
	std::cout << "b * a\t= " << b.operator*(a) << std::endl;
	std::cout << "b + a\t= " << b.operator+(a) << std::endl;
	std::cout << "b - a\t= " << b.operator-(a) << std::endl;
	std::cout << std::endl;

//max min
	std::cout << "max(" << a << ", " << b << ")\t = " << Fixed::max(a, b) << std::endl;
	std::cout << "min(" << a << ", " << b << ")\t = " << Fixed::min(a, b) << std::endl;
	std::cout << std::endl;

	return 0;
}
