/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:18:21 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/13 15:33:50 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string	upper(std::string str)
{
	for (std::string::iterator it = str.begin() ; it != str.end() ; ++it)
		*it = std::toupper(*it);
	return (str);
}

void	megaphone(int ac, char **av, std::string str)
{
	int		i = 0;

	while (++i < ac)
	{
		while (av[i])
		{
			str.append(upper(av[i]));
			i++;
		}
	}
	std::cout << str;
}

int	main(int ac, char **av)
{
	std::string	str = "";

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		megaphone(ac, av, str);
		std::cout << std::endl;
	}
	return (0);
}
