/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:32:13 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/19 15:41:05 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main()
{
	Karen	momFromHell;

	std::cout << "Narrator: Karen was on her way to her favorite fast food. But "
	<< "a tragedy was about to happen..." << std::endl << std::endl;

	std::cout << "[Karen, debug level] "<< std::endl;
	momFromHell.complain("debug");
	std::cout << std::endl;

	std::cout << "[Karen, info level] "<< std::endl;
	momFromHell.complain("info");
	std::cout << std::endl;

	std::cout << "[Karen, warning level] "<< std::endl;
	momFromHell.complain("warning");
	std::cout << std::endl;

	std::cout << "[Karen, error level] "<< std::endl;
	momFromHell.complain("error");
	std::cout << std::endl;

	std::cout << "[Karen, not a possible level] "<< std::endl;
	momFromHell.complain("not a possibility");
	std::cout << std::endl;

	return (0);
}
