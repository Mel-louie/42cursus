/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:47:52 by louielouie        #+#    #+#             */
/*   Updated: 2021/07/14 14:02:56 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	usage(int code)
{
	if (code == 1)
	{
		printf("-- First agument is the number of Philosophers\n");
		printf(" \t must be between 1 and 200.\n");
	}
}

int	get_arg(int ac, char **av, t_settings *set)
{
	set->philos_nb = ft_atoi(av[1]);
	if (set->philos_nb < 1 || set->philos_nb > 200)
	{
		usage(1);
		return (2);
	}
	set->t_to_die = ft_atoi(av[2]);
	set->t_to_eat = ft_atoi(av[3]);
	set->t_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		set->opt_must_eat_nb = ft_atoi(av[5]);
	return (0);
}
