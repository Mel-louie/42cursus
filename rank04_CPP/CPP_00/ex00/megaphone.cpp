/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:01:56 by louielouie        #+#    #+#             */
/*   Updated: 2021/09/10 13:47:02 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	megaphone(int ac, char **av)
{
	int		i = 0;
	int		j = 0;

	while (++i < ac)
	{
		while (av[i][j])
		{
			putchar(toupper(av[i][j]));
			j++;
		}
		j = 0;
	}
	std::cout << std::endl;
}

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		megaphone(ac, av);
	return (0);
}
