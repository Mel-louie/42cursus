/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:29:36 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/05 15:18:25 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <set>
#include <string>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include "../includes/easyfind.hpp"
#include "../includes/easyfindTests.hpp"

int	main( void )
{	
	std::deque<int>	contDeque;
	std::vector<int>	contVector;
	std::list<int>	contList;
	std::set<int>	contSet;

	std::cout << "<--- TEST WITH AN INT ARRAY IN DEQUE CONTAINER, to find 1, 2, and 42 --->" << std::endl;
	test( contDeque, 1, 2, 42 ); std::cout << std::endl;
	std::cout << "<---=================================================================--->\n" << std::endl;

	std::cout << "<--- TEST WITH AN INT ARRAY IN VECTOR CONTAINER, to find 33, 3 and 26 --->" << std::endl;
	test( contVector, 33, 3, 26 ); std::cout << std::endl;
	std::cout << "<---=================================================================--->\n" << std::endl;
	
	std::cout << "<--- TEST WITH AN INT ARRAY IN LIST CONTAINER, to find 15, 4 and 28 --->" << std::endl;
	testWoIndex( contList, 15, 4, 28 ); std::cout << std::endl;
	std::cout << "<---================================================================--->\n" << std::endl;

	std::cout << "<--- TEST WITH AN INT ARRAY IN SET CONTAINER, to find 7, 44, and 9 --->" << std::endl;
	testWoIndex( contSet, 7, 44, 9 ); std::cout << std::endl;
	std::cout << "<---=================================================================--->\n" << std::endl;
	
	return (0);
}
