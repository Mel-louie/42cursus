/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:41:19 by louielouie        #+#    #+#             */
/*   Updated: 2021/08/11 15:15:08 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <string.h>

int	main(int ac, char **av)
{
	t_structs	s;
	// int			i;

	if (handle_errors(ac, av) == 1)
		return (1);
	get_arg(ac, av, &s);
	s.ps = malloc(sizeof(t_philo_struct) * s.arg.philos);
	if (s.ps == NULL)
	{
		printf("Error on memory allocation.\n"); //faire fonction exit
		return (3);
	}
	if (!init_philos(&s) || !create_threads(&s))
		printf("init fail\n"); //
	

	// i = 0;
	// while (i < s.arg.philos)
	// {
	// 	pthread_join(s.ps[i].thread_id, NULL);
	// 	i++;
	// }
	free(s.ps);
	return (0);
}
