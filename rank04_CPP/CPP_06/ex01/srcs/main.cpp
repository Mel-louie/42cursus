/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:03:39 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/02 21:36:46 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serialize.hpp"


uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>( ptr ));
}

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>( raw ));
}

int	main( void )
{
	Data	dataTest;

	uintptr_t	serializedData = serialize(&dataTest);
	Data*		resultDeserialized = deserialize(serializedData);
	
	std::cout << "dataTest adress:\t\t\t\t\t\t" << &dataTest << std::endl;
	std::cout << "dataTest adress after serialization:\t\t\t\t" << serializedData << std::endl;
	std::cout << "dataTest adress after serialization then deserialization:\t" << deserialize(serialize(&dataTest)) << std::endl;
	std::cout << "resultDeserialized adress after deserialization:\t\t" << resultDeserialized << std::endl;

	return (0);
}
