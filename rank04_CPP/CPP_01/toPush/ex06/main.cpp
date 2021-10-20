/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:32:13 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/19 17:31:29 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void	displayUsages()
{
	std::cout << "You have to pass an ARG to ./karenFilter:" << std::endl
	<< "Examples:" << std::endl
	<< "\t./karenFilter \"DEBUG\"" << std::endl
	<< "\t./karenFilter \"INFO\"" << std::endl
	<< "\t./karenFilter \"WARNING\"" << std::endl
	<< "\t./karenFilter \"ERROR\"" << std::endl
	<< "Or\t./karenFilter \"whatever\""
	<< std::endl;
}

int	main(int ac, char **av)
{
	Karen	momFromHell;
	int		i = -1;
	std::string	arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (ac != 2)
	{
		displayUsages();
		return (1);
	}

	while (++i < 4)
		if ( arr[i].compare(av[1]) == 0)
			break ;

	switch (i)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			momFromHell.complain("debug");
			std::cout << std::endl;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			momFromHell.complain("info");
			std::cout << std::endl;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			momFromHell.complain("warning");
			std::cout << std::endl;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			momFromHell.complain("error");
			std::cout << std::endl;
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
