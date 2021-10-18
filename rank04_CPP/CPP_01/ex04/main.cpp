/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:09:14 by user42            #+#    #+#             */
/*   Updated: 2021/10/18 16:52:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int	main(int ac, char **av)
{
	( void )ac;
	std::ifstream	file( av[1] );
	std::string	dest;
	
	if ( file )
	{
		std::ostringstream	buffer;
		buffer << file.rdbuf();
		file.close();

		dest = buffer.str();
		std::cout << dest << std::endl;
	}
	return (0);
}
