/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:34:25 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/14 13:16:45 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassTests.hpp"

int	main( void )
{
	Sample	sample;
	int	val;

	std::cout << "Bliblou\t: ";
	sample.bliblou();
	
	//set value
	std::cout << "Choose a value: ";
	std::cin >> val;
	sample.setVal(val);

	std::cout << "get value\t: ";
	std::cout << sample.getVal() << std::endl;
	
	return (0);
}
