/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:18:21 by mdesfont          #+#    #+#             */
/*   Updated: 2021/09/06 15:33:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data		data;
	t_philo		*philo;
	pthread_t	*thread;

	if (ac < 5 || ac > 6)
		return (ft_putstr_fd("Wrong number of arguments\n", 1, 0));
	if (parsing(&data, ac, av))
		return (ft_putstr_fd("Parsing error\n", 1, 0));
	philo = malloc(sizeof(t_philo) * data.num);
	if (!philo)
		return (ft_putstr_fd("Can't malloc\n", 1, 0));
	thread = malloc(sizeof(pthread_t) * data.num);
	if (!thread)
		return (ft_putstr_fd("Can't malloc\n", 1, 0));
	if (set_threads(&data, philo, thread))
		return (ft_putstr_fd("Thread error\n", 1, 0));
	free(philo);
	free(thread);
	free(data.forks);
	return (0);
}
