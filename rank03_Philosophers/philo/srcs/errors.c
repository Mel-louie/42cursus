/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:44:21 by mdesfont          #+#    #+#             */
/*   Updated: 2021/07/08 13:10:32 by mdesfont         ###   ########.fr       */
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
			printf("You can only run the program with numbers.\n");
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
