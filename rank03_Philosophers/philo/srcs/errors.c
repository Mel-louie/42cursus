/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:44:21 by mdesfont          #+#    #+#             */
/*   Updated: 2021/07/10 15:36:31 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

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
		if (check_num(av[i]) == 1 || ft_strcmp(av[1], "0") == 0)
		{
			printf("Error\nYou can only run the program with");
			printf(" positives integers.\n");
			if (ft_strcmp(av[1], "0") == 0)
			{
				printf("The first number is the number of philosophers. ");
				printf("Should be >= 1.\n");
			}
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
