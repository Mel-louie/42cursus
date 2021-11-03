/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:23:44 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/03 20:58:23 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include <iostream>
#include <cstdlib>

int main() {

	Array<int> arrayInt(5);

	std::cout << "---------- ARRAY OF INT ----------";
	std::cout << std::endl;
	
	std::cout << "Before changing value (arrayInt[0]):\t";
	displayElement(arrayInt, 0);
	
	arrayInt[0] = 2;
	std::cout << std::endl;
	std::cout << "After changing value (arrayInt[0]):\t";
	displayElement(arrayInt, 0);
	
	std::cout << std::endl;
	std::cout << "Index beyond limits (arrayInt[12]):\t";	
	displayElement(arrayInt, 12);
	std::cout << std::endl;
	
	
	std::cout << "---------- ARRAY OF STRING ----------";
	Array<std::string> arrayString(5);
	
	std::cout << std::endl;
	std::cout << "Before changing value (arrayString[3]):\t\t\t|";
	displayElement(arrayString, 3); std::cout << "|";
	
	arrayString[3] = "Hello World!";
	std::cout << std::endl;
	std::cout << "After changing value (arrayString[3] = \"Hello World!\"):\t|";
	displayElement(arrayString, 3); std::cout << "|";
	
	std::cout << std::endl;
	std::cout << "Index beyond limits (arrayString[31]):\t\t\t";
	displayElement(arrayString, 31);
	std::cout << std::endl;


	std::cout << "---------- ARRAY OF STRING COPY ----------";
	Array<std::string> arrayStringCopy(arrayString);

	std::cout << std::endl;
	std::cout << "(arrayStringCopy[3]), copy from arrayString:\t\t";
	displayElement(arrayStringCopy, 3);
	std::cout << std::endl;

	arrayString[3] = "Hi Mom!";
	std::cout << "Modification of the original arrayString:\t\t";
	displayElement(arrayString, 3);
	std::cout << std::endl;
	std::cout << "Check if the arrayStringCopy has changed (shouldn't):\t";
	displayElement(arrayStringCopy, 3);
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "---------- EMPTY ARRAY ----------";
	Array<int> arrayEmpty;

	std::cout << std::endl;
	std::cout << "arrayInt size:\t\t" << arrayInt.size();

	std::cout << std::endl;
	std::cout << "arrayEmpty size:\t" << arrayEmpty.size();

	std::cout << std::endl;
	std::cout << "Copy arrayInt in arrayEmpty";

	std::cout << std::endl;
	arrayEmpty = arrayInt;
	std::cout << "arrayEmpty size:\t" << arrayEmpty.size();
	
	std::cout << std::endl;

	//leaks macos
	// system( "leaks array" );
	return (0);
}