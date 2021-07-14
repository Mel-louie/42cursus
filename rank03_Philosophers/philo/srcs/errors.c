/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:44:21 by mdesfont          #+#    #+#             */
/*   Updated: 2021/07/14 13:52:36 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_num(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		if (str[c] < '0' || str[c] > '9')
			return (1);
		c++;
	}
	return (0);
}

int	handle_errors(int ac, char **av)
{
	int	i;

	i = ac - 1;
	while (i)
	{
		if (check_num(av[i]) == 1)
		{
			printf("Error\nYou can only run the program with");
			printf(" positives integers.\n");
			return (1);
		}
		i--;
	}
	if (ac < 5 || ac > 6)
	{
		printf("Wrong number of arguments.\n");
		return (1);
	}
	return (0);
}
