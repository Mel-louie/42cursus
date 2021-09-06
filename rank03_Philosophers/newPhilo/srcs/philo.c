/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:18:21 by mdesfont          #+#    #+#             */
/*   Updated: 2021/09/06 18:30:31 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	one_philo(t_philo *philo, t_data *data)
{
	if (data->num == 1)
		pthread_mutex_unlock(philo->lfork_mutex);
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

int	main(int ac, char **av)
{
	t_data		data;
	t_philo		*philo;
	pthread_t	*thread;

	if (handle_errors(ac, av) == 1)
		return (1);
	if (parsing(&data, ac, av))
		return (ft_putstr_fd("Error\nWrong type of arguments\n", 1, 0));
	philo = malloc(sizeof(t_philo) * data.num);
	if (!philo)
		return (ft_putstr_fd("Can't malloc\n", 1, 0));
	thread = malloc(sizeof(pthread_t) * data.num);
	if (!thread)
		return (ft_putstr_fd("Can't malloc\n", 1, 0));
	if (set_threads(&data, philo, thread))
		return (ft_putstr_fd("Something went wrong with threads init\n", 1, 0));
	free(philo);
	free(thread);
	free(data.forks);
	return (0);
}
